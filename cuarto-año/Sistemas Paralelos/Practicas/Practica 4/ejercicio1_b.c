#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

void master(size_t N, int cant_proc);
void slave(size_t N, int cant_proc);


double
dwalltime()
{
        double sec;
        struct timeval tv;

        gettimeofday(&tv, NULL);
        sec  =  tv.tv_sec + tv.tv_usec/1000000.0;
        return sec;
}

int
main(int argc, char*argv[])
{
        int rank, size;
        int N  =  atoi(argv[1]);
        double timetick;

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

        return(0);
}


void
master(size_t N, int cant_proc)
{
        double *A, *B, *C, *AUX;
        double timetick, tmp;
        int check = 1;
        size_t i, j, k;
        size_t matrix_size = N*N;
        size_t n_limit = N/cant_proc;

        MPI_Status status;
        MPI_Request req;

        A = (double*) malloc(matrix_size*sizeof(double));
        B = (double*) malloc(matrix_size*sizeof(double));
        C = (double*) malloc(matrix_size*sizeof(double));
        AUX = (double*) malloc(matrix_size*sizeof(double));

        timetick  =  dwalltime();
        //Inicializa las matrices A y B en 1, el resultado sera una matriz con todos sus valores en N
        for (i = 0; i < N; i++)
        {
                for (j = 0; j < N; j++)
                {
                        A[i*N+j] = 1;
                        B[i*N+j] = 1;
                }
        }


//Envia la matriz B y una porcion de la matriz A a cada proceso
        int base = N*N/cant_proc;
        MPI_Bcast(B, N*N, MPI_DOUBLE, 0, MPI_COMM_WORLD);
        MPI_Scatter(A, base, MPI_DOUBLE, AUX, base, MPI_DOUBLE, 0, MPI_COMM_WORLD);


        //Realiza la multiplicacion
        for (i = 0; i < n_limit; i++)
        {
                for (j = 0; j < N; j++)
                {
                        tmp = 0.;
                        for (k = 0; k < N; k++)
                        {
                                tmp += A[i*N+k]*B[k+j*N];
                        }

                        AUX[i*N+j] = tmp;
                }
        }

        MPI_Gather(AUX, base, MPI_DOUBLE, C, base, MPI_DOUBLE, 0, MPI_COMM_WORLD);

        for (i = 0; i < N; i++)
        {
                for (j = 0; j < N; j++)
                {
                        check = check && (C[i*N+j] == N);
                }
        }

        if(check)
        {
                printf("Success!\n");
        }
        else
        {
                printf("Failure\n");
        }

        free(A);
        free(B);
        free(C);

        printf("Time in seconds: %fs\n", dwalltime() - timetick);

}

void
slave(size_t N, int cant_proc)
{
        double *A, *B, *C;
        double tmp;
        size_t i, j, k;
        size_t matrix_size = N*N;
        size_t n_limit = N/cant_proc;

        MPI_Status status;
        MPI_Request req;


        int base = N*N/cant_proc;
        B = (double*) malloc(matrix_size*sizeof(double));
        A = (double*) malloc(base*sizeof(double));
        C = (double*) malloc(base*sizeof(double));

        MPI_Bcast(B, matrix_size, MPI_DOUBLE, 0, MPI_COMM_WORLD);
        MPI_Scatter(A, base, MPI_DOUBLE, A, base, MPI_DOUBLE, 0, MPI_COMM_WORLD);

        for (i = 0; i < n_limit; i++)
        {
                for (j = 0; j < N; j++)
                {
                        tmp = 0.;
                        for (k = 0; k < N; k++)
                        {
                                tmp += A[i*N+k]*B[k+j*N];
                        }

                        C[i*N+j] = tmp;
                }
        }

        MPI_Gather(C, base, MPI_DOUBLE, C, base, MPI_DOUBLE, 0, MPI_COMM_WORLD);

        free(A);
        free(B);
        free(C);
}
