#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define PRINTABLE_TIME(_x) ((long double) (clock() - _x)/CLOCKS_PER_SEC)

int
main(int argc, char const *argv[])
{
        clock_t cl;
        size_t N, i, p = 0, *A;

        if (argc < 2)
        {
                printf("  Faltan argumentos: N dimension del arreglo. \n");
                exit(-1);
        }

        N = atoi(argv[1]);
        A = (size_t*) malloc(sizeof(size_t) * N);

        for (i = 0; i < N; i++)
        {
                A[i] = i;
        }

        cl = clock();

        for (i = 0; i < N; i++)
        {
                p += !(A[i] % 2);
        }

        printf("  Time: %Lfs\n", PRINTABLE_TIME(cl));

        return 0;
}
