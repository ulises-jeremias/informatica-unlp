#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <secuencial/matrix.h>

#define PRINTABLE_TIME(_x) ((long double) (clock() - _x)/CLOCKS_PER_SEC)

int
main(int argc, char const *argv[])
{
        size_t N, r, n, matrix_size, block_size;
        double l, b, *A, *B, *C, *D, *L, *AM, *BM, *R;
        clock_t cl;

        if (argc < 3) {
                printf("\n Falta un parametro ");
                printf("\n 1. Cantidad de bloques por dimension ");
                printf("\n 2. Dimension de cada bloque ");
                exit(-1);
        }

        n = atoi(argv[1]);
        r = atoi(argv[2]);

        N = n*r; //dimension de la matriz
        matrix_size = N*N; //cantidad total de datos matriz
        block_size = r*r; //cantidad total de datos del bloque

        matrix_set_blocks_count(n);
        matrix_set_block_size(r);

        A = (double *) malloc(sizeof(double)*matrix_size);
        B = (double *) malloc(sizeof(double)*matrix_size);
        C = (double *) malloc(sizeof(double)*matrix_size);
        D = (double *) malloc(sizeof(double)*matrix_size);
        L = (double *) malloc(sizeof(double)*matrix_size);
        AM = (double *) malloc(sizeof(double)*matrix_size);
        BM = (double *) malloc(sizeof(double)*matrix_size);
        R = (double *) malloc(sizeof(double)*matrix_size);

        matrix_init(A);
        matrix_init(B);
        matrix_init(C);
        matrix_triangular_init(L);

        vector_avg(B, &b);
        vector_avg(L, &l);

        #ifdef DEBUG
        matrix_printf(A);
        matrix_printf(B);
        matrix_printf(C);
        matrix_printf(L);
        printf("%f\n", l);
        printf("%f\n", b);
        #endif

        cl = clock();

        matrix_block_mult(A, B, AM);
        matrix_block_mult(AM, C, A);
        matrix_mult_scalar(A, l, AM);

        matrix_block_mult(B, D, BM);
        matrix_triangular_mult(L, BM, D);
        matrix_mult_scalar(D, b, BM);

        matrix_add(AM, BM, R);

        printf("TIME: %Lf\n", PRINTABLE_TIME(cl));

        //matrix_printf(R);

        free(A);
        free(B);
        free(D);
        free(L);
        free(AM);
        free(BM);
        free(R);

        return 0;
}
