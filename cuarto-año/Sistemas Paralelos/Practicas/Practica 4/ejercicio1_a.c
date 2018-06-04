#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <mpi.h>

void master(size_t N, int cant_proc);
void slave(size_t N, int cant_proc);

double
dwalltime()
{
        double sec;
        struct timeval tv;

        gettimeofday(&tv,NULL);
        sec = tv.tv_sec + tv.tv_usec/1000000.0;
        return sec;
}

int
main(int argc, char *argv[])
{
        int rank, size;
        size_t N = (size_t) atoi(argv[1]);

        MPI_Init(&argc, &argv);

        MPI_Comm_size(MPI_COMM_WORLD, &size);
        MPI_Comm_rank(MPI_COMM_WORLD, &rank);

        if (rank == 0)
        {
                master(N, size);
        }
        else
        {
                slave(N, size);
        }

        MPI_Finalize();

        return 0;
}

void
master(size_t N, int cant_proc)
{
        double *A, *B, *C;
        double timetick, tmp;
        size_t i, j, k;
        int check = 1;

        MPI_Status status;
        MPI_Request req;

        size_t matrix_size = N*N;
        size_t base = matrix_size/cant_proc;
        size_t n_limit = N/cant_proc;

        A = (double *) malloc(matrix_size*sizeof(double));
        B = (double *) malloc(matrix_size*sizeof(double));
        C = (double *) malloc(matrix_size*sizeof(double));

        for (i = 0; i < N; i++)
        {
                for (j = 0; j < N; j++)
                {
                        A[i*N + j] = 1.;
                        B[i*N + j] = 1.;
                }
        }

        timetick = dwalltime();

        for (i = 1; i < cant_proc; i++)
        {
                MPI_Send(B, matrix_size, MPI_DOUBLE, i, 1, MPI_COMM_WORLD);
                MPI_Send(A + i*base, base, MPI_DOUBLE, i, 2, MPI_COMM_WORLD);
        }

        for (i = 0; i < n_limit; i++)
        {
                for (j = 0; j < N; j++)
                {
                        tmp = 0.0;

                        for (k = 0; k < N; k++)
                        {
                                tmp += A[i*N+k]*B[k+j*N];
                        }

                        C[i*N + j] = tmp;
                }
        }

        for (i = 1; i < cant_proc; i++)
        {
                MPI_Recv(C + i*base, base, MPI_DOUBLE, i, 3, MPI_COMM_WORLD, &status);

        }

        printf("Time in seconds: %fs\n", dwalltime() - timetick);

        for (i = 0; i < N; i++)
        {
                for (j = 0; j < N; j++)
                {
                        check = check && (C[i*N + j]==N);
                }
        }

        if(check)
        {
                printf("Success!\n");
        }
        else
        {
                printf("Failure :c\n");
        }

        free(A);
        free(B);
        free(C);
}

void
slave(int N, int cant_proc){
        double *A, *B, *C;
        size_t i, j, k;
        size_t matrix_size = N*N;
        size_t base = matrix_size/cant_proc;
        size_t n_limit = N/cant_proc;

        MPI_Status status;
        MPI_Request req;


        B = (double*) malloc(matrix_size*sizeof(double));
        A = (double*) malloc(base*sizeof(double));
        C = (double*) calloc(base*sizeof(double));

        MPI_Recv(B, matrix_size, MPI_DOUBLE, 0, 1, MPI_COMM_WORLD, &status);
        MPI_Recv(A, base, MPI_DOUBLE, 0, 2, MPI_COMM_WORLD, &status);

        for (i = 0; i < n_limit; i++)
        {
                for (j = 0; j < N; j++)
                {
                        tmp = 0.0;
                        for (k = 0; k < N; k++)
                        {
                                tmp += A[i*N+k]*B[k+j*N];
                        }

                        C[i*N+j] = tmp;
                }
        }

        MPI_Send(C, base, MPI_DOUBLE, 0, 3, MPI_COMM_WORLD);

        free(A);
        free(B);
        free(C);
}
