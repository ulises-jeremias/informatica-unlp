#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <secuencial/matrix.h>

static size_t n = 4;
static size_t r = 4;

__EXTERN_INLINE void
matrix_get_blocks_count(size_t *size)
{
        *size = n;
}

__EXTERN_INLINE void
matrix_set_blocks_count(size_t size)
{
        n = size;
}

__EXTERN_INLINE void
matrix_get_block_size(size_t *size)
{
        *size = r;
}

__EXTERN_INLINE void
matrix_set_block_size(size_t size)
{
        r = size;
}

__EXTERN_INLINE void
matrix_init(double *S)
{
        size_t i, N = n*r, matrix_size = N*N;

        for (i = 0; i < matrix_size; i++)
        {
                S[i] = i%10;
        }
}

__EXTERN_INLINE void
matrix_triangular_init(double *S)
{
        size_t i, j, N = r*n;

        for (i = 0; i < N; i++)
        {
                for (j = 0; j < N; j++)
                {

                        S[i*N + j] = (i >= j);
                }
        }
}

__EXTERN_INLINE void
matrix_printf(double *S)
{
        size_t i, j, I, J, delta;

        printf("Matrix content: \n ");

        for (I = 0; I < n; I++)
        {
                for (i = 0; i < r; i++)
                {
                        for (J = 0; J < n; J++)
                        {
                                delta = (I*n + J)*r*r;
                                for (j = 0; j < r; j++)
                                {
                                        printf("%f ",S[delta + i*r + j]);

                                }
                        }

                        printf("\n ");
                }

        }

        printf(" \n\n");
}

__EXTERN_INLINE void
vector_sum(double *S, double *sum)
{
        size_t i, matrix_size = r*r*n*n;
        double local_sum = 0;

        for (i = 0; i < matrix_size; i++)
        {
                local_sum += S[i];
        }

        *sum = local_sum;
}

__EXTERN_INLINE void
vector_avg(double *S, double *avg)
{
        size_t i, matrix_size = r*r*n*n;
        double local_sum = 0;

        for (i = 0; i < matrix_size; i++)
        {
                local_sum += S[i];
        }

        *avg = local_sum/matrix_size;
}

__EXTERN_INLINE void
vector_printf(double *S)
{
        size_t i, matrix_size = r*r*n*n;

        printf("\n ");
        for (i = 0; i < matrix_size; i++)
        {
                printf(" %f ", S[i]);
        }

        printf("\n\n ");
}

__EXTERN_INLINE void
matrix_mult_scalar(double *A, double a, double *B)
{
        size_t i, matrix_size = r*r*n*n;

        for (i = 0; i < matrix_size; i++) B[i] = A[i] * a;
}

__EXTERN_INLINE void
matrix_add(double *A, double *B, double *C)
{
        size_t i, matrix_size = r*r*n*n;

        for (i = 0; i < matrix_size; i++) C[i] = A[i] + B[i];
}

__EXTERN_INLINE void
matrix_block_mult(double *A, double *B, double *C)
{
        size_t I, J, K, i, j, k, N = n*r, despA, despB, despC, desp;
        size_t matrix_size = N*N, block_size = r*r;
        double tmp;

        for (i = 0; i < matrix_size; i++) C[i] = 0.0;

        for (I = 0; I < n; I++)
        {
                for (J = 0; J < n; J++)
                {
                        despC = (I*n+J)*block_size;

                        for (K=0; K < n; K++)
                        {
                                despA = (I*n+K)*block_size;
                                despB = (K*n+J)*block_size;

                                for (i = 0; i < r; i++)
                                {
                                        for (j = 0; j < r; j++)
                                        {
                                                desp = despC + i*r+j;
                                                tmp = 0;

                                                for (k=0; k < r; k++)
                                                {
                                                        tmp += A[despA + i*r+k]*B[despB + k*r+j];
                                                }

                                                C[desp] += tmp;
                                        }
                                }
                        }
                }
        }
}

__EXTERN_INLINE void
matrix_triangular_mult(double *A, double *B, double *C)
{
        size_t i, j, k, N = r*n;
        double tmp;

        for (i = 0; i < N; i++)
        {
                for (j = 0; j < N; j++)
                {
                        tmp = 0;

                        for (k = j; k < N; k++)
                        {
                                tmp += A[i*N + k]*B[k + j*N];
                        }

                        C[i*N+j] += tmp;
                }
        }
}
