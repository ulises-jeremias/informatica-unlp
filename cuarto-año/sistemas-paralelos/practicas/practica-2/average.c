#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include <pthread.h>

int NUM_THREADS = 4;
int N = 100;
int X = 0;
double average = 0.0;

double *A;

pthread_mutex_t avg_mutex;
pthread_barrier_t avg_barrier;

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
        long i, tid;
        tid = (long) threadid;
        printf("Hello World! It's me, thread #%ld!\n", tid);

        long limit = (1 + tid)*(N/NUM_THREADS);
        for (i = tid*(N/NUM_THREADS); i < limit; i++)
        {
                A[i] = tid % 2;
        }
}

void *
calc_avg(void *threadid)
{
        long i, tid;
        double local_avg = 0.0;
        tid = (long) threadid;

        printf("Hello World! It's me, thread #%ld again! :D\n", tid);

        long limit = (1 + tid)*(N/NUM_THREADS);

        for (i = tid*(N/NUM_THREADS); i < limit; i++)
        {
                local_avg += A[i];
        }

        pthread_mutex_lock(&avg_mutex);
        average += local_avg;
        pthread_mutex_unlock(&avg_mutex);

        pthread_barrier_wait(&avg_barrier);

        if (tid == 0) {
                average /= N;
        }
}

int
main(int argc, const char *argv[])
{
        long i;
        double timetick;

        if ((argc != 2) || ((N = atoi(argv[1])) <= 0))
        {
                printf("\nUsar: %s n\n  n: Dimension de la matriz (nxn X nxn)\n", argv[0]);
                exit(1);
        }

        A = (double*) malloc(sizeof(double)*N);

        int rc;

        pthread_mutex_init(&avg_mutex, NULL);
        pthread_barrier_init(&avg_barrier, NULL, NUM_THREADS);

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
                rc = pthread_create(&threads[i], &attr, calc_avg, (void *)i);
        }

        barrier(threads, &attr);

        printf("Time in seconds %f\n", dwalltime() - timetick);

        double avg = 0.0;

        for (i = 0; i < N; i++)
        {
                avg += A[i];
        }

        avg /= N;

        if (avg == average)
        {
                printf("Correct answer\n");
        }
        else
        {
                printf("Wrong answer\n");
        }

        free(A);

        pthread_exit(NULL);

        return(0);
}
