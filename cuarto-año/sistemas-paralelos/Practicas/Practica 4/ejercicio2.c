#include <stdlib.h>
#include <stdio.h>
#include <mpi.h>

void master(size_t N, int cant_proc);
void slave(size_t N, int cant_proc);

double
dwalltime()
{
        double sec;
        struct timeval tv;

        gettimeofday(&tv, NULL);
        sec = tv.tv_sec + tv.tv_usec/1000000.0;
        return sec;
}

int
main(int argc, char *argv[])
{
        int rank, size;
        double timetick;
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
        double *A, *B, *AUX, *AUXB;
        double timetick, tmp;
        double max = 0.;
        double min = 999.;
        double sum = 0., avg;
        int check = 1;
        size_t i, j;
        size_t matrix_size = N*N;
        size_t n_limit = N/cant_proc;
        size_t base = matrix_size/cant_proc;

        A = (double*) malloc(matrix_size*sizeof(double));
        B = (double*) malloc(matrix_size*sizeof(double));
        AUX = (double*) malloc(base*sizeof(double));
        AUXB = (double*) malloc(base*sizeof(double));

        for (i = 0; i < matrix_size; i++) A[i] = (double) i;

        timetick = dwalltime();

        MPI_Scatter(A, base, MPI_DOUBLE, AUX, base, MPI_DOUBLE, 0, MPI_COMM_WORLD);

        for (i = 0; i < n_limit; i++)
        {
                for (j = 0; j < N; j++)
                {
                        tmp = AUX[i*N+j];

                        if (tmp > max)
                        {
                                max = tmp;
                        }

                        if (tmp < min)
                        {
                                min = tmp;
                        }

                        sum += tmp;
                }
        }

        MPI_Allreduce(&sum, &sum, 1, MPI_DOUBLE, MPI_SUM, MPI_COMM_WORLD);
        MPI_Allreduce(&max, &max, 1, MPI_DOUBLE, MPI_MAX, MPI_COMM_WORLD);
        MPI_Allreduce(&min, &min, 1, MPI_DOUBLE, MPI_MIN, MPI_COMM_WORLD);

        avg = sum/matrix_size;

        for (i = 0; i < n_limit; i++)
        {
                for (j = 0; j < N; j++)
                {
                        tmp = AUX[i*N+j];

                        if (tmp > avg)
                        {
                                AUXB[i*N+j] = max;
                        }
                        else if (tmp<avg)
                        {
                                AUXB[i*N+j] = min;
                        }
                        else
                        {
                                AUXB[i*N+j] = avg;
                        }
                }
        }

        MPI_Gather(AUXB, base, MPI_DOUBLE, B, base, MPI_DOUBLE, 0, MPI_COMM_WORLD);

        printf("Time in seconds: %fs\n", dwalltime() - timetick);

        for (i = 0; i<N; i++)
        {
                for (j = 0; j<N; j++)
                {
                        tmp = B[i*N+j];

                        if (tmp > avg)
                        {
                                check = check && (B[i*N+j]==max);
                        }
                        else if (tmp < avg)
                        {
                                check = check && (B[i*N+j]==min);
                        }
                        else {
                                check = check && (B[i*N+j]==avg);
                        }
                }
        }

        printf("Max: %f, min: %f, average: %f\n", max, min, avg);

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


}

void
slave(size_t N, int cant_proc)
{
        double *A, *B;
        double max = 0.;
        double min = 999.;
        double sum = 0., avg;
        size_t i, j;
        size_t matrix_size = N*N;
        size_t base = matrix_size/cant_proc;
        size_t n_limit = N/cant_proc;

        A = (double*) malloc(base*sizeof(double));
        B = (double*) malloc(base*sizeof(double));

        MPI_Scatter(A, base, MPI_DOUBLE, A, base, MPI_DOUBLE, 0, MPI_COMM_WORLD);

        for (i = 0; i < n_limit; i++)
        {
                for (j = 0; j < N; j++)
                {
                        tmp = A[i*N+j];

                        if (tmp > max)
                        {
                                max = tmp;
                        }

                        if (tmp < min)
                        {
                                min = tmp;
                        }

                        sum += tmp;
                }
        }

        MPI_Allreduce(&sum, &sum, 1, MPI_DOUBLE, MPI_SUM, MPI_COMM_WORLD);
        MPI_Allreduce(&max, &max, 1, MPI_DOUBLE, MPI_MAX, MPI_COMM_WORLD);
        MPI_Allreduce(&min, &min, 1, MPI_DOUBLE, MPI_MIN, MPI_COMM_WORLD);

        avg = sum/matrix_size;

        for (i = 0; i< n_limit; i++)
        {
                for (j = 0; j < N; j++)
                {
                        tmp = A[i*N+j];

                        if (tmp > avg)
                        {
                                B[i*N+j] = max;
                        }
                        else if (tmp<avg)
                        {
                                B[i*N+j] = min;
                        }
                        else
                        {
                                B[i*N+j] = avg;
                        }
                }
        }

        MPI_Gather(B, base, MPI_DOUBLE, B, base, MPI_DOUBLE, 0, MPI_COMM_WORLD);

        free(A);
        free(B);
}
