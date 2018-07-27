#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <omp.h>

#define PRINTABLE_TIME(_x) ((long double) (clock() - _x)/CLOCKS_PER_SEC)

int
main(int argc, char const *argv[])
{
        size_t N, NUM_THREADS, i, sec_p = 0, p = 0, *A;

        clock_t cl;

        if (argc < 3)
        {
                printf("Faltan argumentos: N dimension del arreglo. \n");
                exit(-1);
        }

        N = atoi(argv[1]);
        NUM_THREADS = atoi(argv[2]);
        omp_set_num_threads(NUM_THREADS);

        A = (size_t*) malloc(sizeof(size_t) * N);

        #pragma omp parallel for shared(A) private(i)
        for (i = 0; i < N; i++)
        {
                A[i] = i;
        }

        cl = clock();


        #pragma omp parallel for private(i) reduction(+:p)
        for (i = 0; i < N; i++)
        {
                p += !(A[i] % 2);
        }

        printf("Time: %Lfs\n", PRINTABLE_TIME(cl));

        for (i = 0; i < N; i++)
        {
                sec_p += !(A[i] % 2);
        }

        if (sec_p != p) {
                printf("Failure\n");
                exit(-1);
        }

        printf("Success!\n");
        return 0;
}
