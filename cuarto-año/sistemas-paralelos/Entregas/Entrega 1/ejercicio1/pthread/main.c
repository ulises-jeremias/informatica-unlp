#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <pthread.h>
#include <matrix.h>

#define PRINTABLE_TIME(_x) ((long double) (clock() - _x)/CLOCKS_PER_SEC)

size_t n, NUM_THREADS = 4, r, N, matrix_size, matrix_tri_size, block_size;

double *A, *B, *C, *D, *L, *R, *AB, *BD, *ABC;
double b = 0.0, l = 0.0;

pthread_mutex_t mutex_l;
pthread_mutex_t mutex_b;
pthread_barrier_t barrier;

void * process(void * argv);

int
main(int argc, char const *argv[])
{
        pthread_t threads[NUM_THREADS];
        size_t i, tids[NUM_THREADS];
        clock_t cl;
        double expected, result;
        long rc;

        if (argc < 4)
        {
                printf("\n Faltan parametros ");
                printf("\n 1. Cantidad de bloques por dimension ");
                printf("\n 2. Dimension de cada bloque ");
                printf("\n 3. Numero de hilos");
                exit(-1);
        }

        n = atoi(argv[1]);
        r = atoi(argv[2]);
        NUM_THREADS = atoi(argv[3]);

        N = n*r;
        matrix_size = N*N;
        matrix_tri_size = N*(N+1)/2;
        block_size = r*r;

        pthread_mutex_init(&mutex_l, NULL);
        pthread_mutex_init(&mutex_b, NULL);
        pthread_barrier_init(&barrier, NULL, NUM_THREADS);

        matrix_set_blocks_count(n);
        matrix_set_block_size(r);

        A = (double *) malloc(matrix_size*sizeof(double));
        B = (double *) malloc(matrix_size*sizeof(double));
        C = (double *) malloc(matrix_size*sizeof(double));
        D = (double *) malloc(matrix_size*sizeof(double));
        R = (double *) malloc(matrix_size*sizeof(double));
        L = (double *) malloc(matrix_tri_size*sizeof(double));
        AB = (double *) calloc(matrix_size, sizeof(double));
        BD = (double *) calloc(matrix_size, sizeof(double));
        ABC = (double *) calloc(matrix_size, sizeof(double));

        matrix_init(A);
        matrix_init(B);
        matrix_init(C);
        matrix_init(D);
        matrix_triangular_init(L);

        #ifdef DEBUG
        matrix_printf(A);
        matrix_printf(B);
        matrix_printf(C);
        matrix_printf(D);
        matrix_triangular_printf(L);
        #endif

        cl = clock();

        for(i = 0; i < NUM_THREADS; i++) {
                tids[i] = i;
                pthread_create(&threads[i], NULL, process, &tids[i]);
        }

        for(i = 0; i < NUM_THREADS; i++) {
                rc = pthread_join(threads[i], NULL);
                #ifdef DEBUG
                printf("join() is %ld\n", threads[i]);
                #endif

                if (rc)
                {
                        printf("ERROR; return code from pthread_join() is %ld\n", rc);
                        exit(-1);
                }
        }

        printf("TIME: %Lf\n", PRINTABLE_TIME(cl));

        expected = matrix_size*(l + 1);
        result = R[matrix_size - 1];

        #ifdef DEBUG
        matrix_printf(AB);
        matrix_printf(BD);
        matrix_printf(ABC);
        matrix_printf(R);

        printf("Results: \n\n");
        printf("  B average: %f\n", b);
        printf("  L average: %f\n", l);
        printf("  Expected result: %f\n", expected);
        printf("  Matrix result: %f\n", result);
        #endif

        if (expected != result) {
                printf("\nFailure\n");
                exit(-1);
        }

        printf("\nSuccess!\n");

        free(A);
        free(B);
        free(D);
        free(L);
        free(R);
        free(AB);
        free(BD);
        free(ABC);

        return 0;
}

void *
process(void * argv)
{
        size_t tid = *(size_t *) argv;
        size_t n_base = tid*N/NUM_THREADS, n_limit = (N/NUM_THREADS)*(tid + 1);
        size_t m_base = tid*matrix_size/NUM_THREADS, m_limit = (matrix_size/NUM_THREADS)*(tid + 1);
        size_t mt_base = tid*matrix_tri_size/NUM_THREADS, mt_limit = (matrix_tri_size/NUM_THREADS)*(tid + 1);
        size_t b_base = tid*n/NUM_THREADS, b_limit = (n/NUM_THREADS)*(tid + 1);
        size_t I, J, K, i, j, k;
        size_t desp1, desp2, desp3, desp, tmp1, tmp2, gauss;
        double local_l = 0.0, local_b = 0.0;


        for (i = m_base; i < m_limit; i++) local_b += B[i];
        for (i = mt_base; i < mt_limit; i++) local_l += L[i];

        pthread_mutex_lock(&mutex_b);
        b += local_b;
        pthread_mutex_unlock(&mutex_b);

        pthread_mutex_lock(&mutex_l);
        l += local_l;
        pthread_mutex_unlock(&mutex_l);

        pthread_barrier_wait(&barrier);
        if (tid == 1)
        {
                b /= matrix_size;
                l /= matrix_size;
        }

        /*
         * AB = A*B
         * BD = B*D
         *
         */
        for (I = b_base; I < b_limit; I++)
        {
                for (J = 0; J < n; J++)
                {
                        desp3 = (I*n+J)*block_size;

                        for (K=0; K < n; K++)
                        {
                                desp1 = (I*n+K)*block_size;
                                desp2 = (K*n+J)*block_size;

                                for (i = 0; i < r; i++)
                                {
                                        for (j = 0; j < r; j++)
                                        {
                                                desp = desp3 + i*r + j;
                                                tmp1 = tmp2 = 0.0;

                                                for (k = 0; k < r; k++)
                                                {
                                                        tmp1 += A[desp1 + i*r+k]*B[desp2 + k*r+j];
                                                        tmp2 += B[desp1 + i*r+k]*D[desp2 + k*r+j];
                                                }

                                                AB[desp] += tmp1;
                                                BD[desp] += tmp2;
                                        }
                                }
                        }
                }
        }

        pthread_barrier_wait(&barrier);

        /*
         * ABC = AB*C
         *
         */
        for (I = b_base; I < b_limit; I++)
        {
                for (J = 0; J < n; J++)
                {
                        desp3 = (I*n+J)*block_size;

                        for (K=0; K < n; K++)
                        {
                                desp1 = (I*n+K)*block_size;
                                desp2 = (K*n+J)*block_size;

                                for (i = 0; i < r; i++)
                                {
                                        for (j = 0; j < r; j++)
                                        {
                                                desp = desp3 + i*r + j;
                                                tmp1 = tmp2 = 0.0;

                                                for (k = 0; k < r; k++)
                                                {
                                                        tmp1 += AB[desp1 + i*r+k]*C[desp2 + k*r+j];
                                                }

                                                ABC[desp] += tmp1;
                                        }
                                }
                        }
                }
        }

        pthread_barrier_wait(&barrier);

        for (i = m_base; i < m_limit; i++) ABC[i] *= l;
        for (i = mt_base; i < mt_limit; i++) L[i] *= b;

        for(i = n_base; i < n_limit; i++)
        {
                tmp2 = i + 1;
                gauss = i*(i+1)/2;

                for(j = 0; j < N; j++)
                {
                        tmp1 = 0.0;

                        for(k = 0; k < tmp2; k++)
                        {
                                tmp1 += L[gauss + k]*BD[k + j*N];
                        }

                        R[i*N + j] += tmp1;
                }
        }

        for (i = m_base; i < m_limit; i++) R[i] += ABC[i];

        pthread_exit(0);

        return NULL;
}
