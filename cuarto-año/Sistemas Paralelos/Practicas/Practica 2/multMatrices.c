#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <pthread.h>

int NUM_THREADS = 4;
int N = 100;
double *A, *B, *C;

double
dwalltime()
{
        double sec;
        struct timeval tv;

        gettimeofday(&tv, NULL);
        sec = tv.tv_sec + tv.tv_usec/1000000.0;

        return sec;
}

void
barrier(pthread_t *threads, pthread_attr_t *attr)
{
        long t, rc;

        pthread_attr_destroy(attr);
        for (t = 0; t < NUM_THREADS; t++)
        {
                rc = pthread_join(threads[t], NULL);
                printf("join() is %d\n", threads[t]);

                if (rc)
                {
                        printf("ERROR; return code from pthread_join() is %d\n", rc);
                        exit(-1);
                }
        }
}

void *
initialize(void *threadid)
{
        long i, j, tid;
        tid = (long) threadid;
        printf("Hello World! It's me, thread #%ld!\n", tid);

        long limit = (1 + tid)*(N/NUM_THREADS);
        for (i = tid*(N/NUM_THREADS); i < limit; i++)
        {
                for (j = 0; j < N; j++)
                {
                        A[i*N + j] = 1.0;
                        B[i + j*N] = 1.0;
                }
        }
}

void *
product(void *threadid)
{
        long i, j, k, tid;
        tid = (long) threadid;
        double acc;
        printf("Hi sir! It's me, thread #%ld again! :D\n", tid);

        long limit = (1 + tid)*(N/NUM_THREADS);
        for (i = tid*(N/NUM_THREADS); i < limit; i++)
        {
                for (j = 0; j < N; j++)
                {
                        acc = 0.0;

                        for(k = 0; k < N; k++)
                        {
                                acc += (A[k*N+j] * B[j+k*N]);
                        }

                        C[i*N+j] = acc;
                }
        }
}

int
main(int argc, const char *argv[])
{
        long i, j;
        int check = 1;
        double timetick;

        if ((argc != 2) || ((N = atoi(argv[1])) <= 0))
        {
                printf("\nUsar: %s n\n  n: Dimension de la matriz (nxn X nxn)\n", argv[0]);
                exit(1);
        }

        A = (double*) malloc(sizeof(double)*N*N);
        B = (double*) malloc(sizeof(double)*N*N);
        C = (double*) calloc(N*N, sizeof(double));

        int rc;

        pthread_t threads[NUM_THREADS];
        pthread_attr_t attr;
        pthread_attr_init(&attr);
        pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

        for (i = 0; i < NUM_THREADS; i++)
        {
                printf("In main: creating thread %ld\n", i);
                rc = pthread_create(&threads[i], &attr, initialize, (void *)i);
        }

        barrier(threads, &attr);

        timetick = dwalltime();

        for (i = 0; i < NUM_THREADS; i++)
        {
                printf("In main: executing thread %ld\n", i);
                rc = pthread_create(&threads[i], &attr, product, (void *)i);
        }

        barrier(threads, &attr);

        printf("Time in seconds %f\n", dwalltime() - timetick);

        for (i = 0; i < N; i++)
        {
                for (j=0; j<N; j++)
                {
                        check = check && (C[i*N + j]==N);
                }
        }

        if (check)
        {
                printf("Correct answer\n");
        }
        else
        {
                printf("Wrong answer\n");
        }

        free(A);
        free(B);
        free(C);

        pthread_exit(NULL);

        return(0);
}
