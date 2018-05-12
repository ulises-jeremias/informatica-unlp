#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <matrix.h>

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
                S[i] = 1.0;
        }
}

__EXTERN_INLINE void
matrix_triangular_init(double *S)
{
        size_t i, N = n*r, M = N*(N+1.)/2.;

        for (i = 0; i < M; i++) S[i] = 1.;
}

__EXTERN_INLINE void
matrix_printf(double *S)
{
        size_t i, j, N = r*n;

        printf("\nMatrix content: \n ");

        for (i = 0; i < N; i++)
        {
                for (j = 0; j < N; j++)
                {

                        printf("%f ", S[i*N + j]);
                }

                printf("\n ");
        }

        printf("\n");
}

__EXTERN_INLINE void
matrix_triangular_printf(double *S)
{
        size_t i, j, N = r*n, gauss;

        printf("Matrix content: \n ");

        for (i = 0; i < N; i++)
        {
                gauss = i*(i+1)/2;

                for (j = 0; j < i + 1; j++)
                {

                        printf("%f ", S[gauss + j]);
                }

                for (; j < N; j++) {
                        printf("%f ", 0.);
                }

                printf("\n ");
        }

        printf("\n\n");
}
