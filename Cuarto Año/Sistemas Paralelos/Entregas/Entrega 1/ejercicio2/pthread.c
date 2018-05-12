#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <pthread.h>

#define PRINTABLE_TIME(_x) ((long double) (clock() - _x)/CLOCKS_PER_SEC)

size_t N, NUM_THREADS, p = 0, *A;
pthread_mutex_t count_mutex;

void *
initialize(void *thread_id)
{
        size_t i, t_id;
        t_id = (size_t) thread_id;
        #ifdef DEBUG
        printf("Hello World! It's me, thread #%ld!\n", t_id);
        #endif

        size_t limit = (1 + t_id)*(N/NUM_THREADS);
        for (i = t_id*(N/NUM_THREADS); i < limit; i++)
        {
                A[i] = i;
        }

        return NULL;
}

void *
counter(void * thread_id)
{
        size_t i, t_id, limit, local_count = 0;
        t_id = (size_t) thread_id;

        #ifdef DEBUG
        printf("Hello World! It's me, thread #%ld again! :D\n", t_id);
        #endif

        limit = (1 + t_id)*(N/NUM_THREADS);

        for (i = t_id*(N/NUM_THREADS); i < limit; i++)
        {
                local_count += !(A[i] % 2);
        }

        pthread_mutex_lock(&count_mutex);
        p += local_count;
        pthread_mutex_unlock(&count_mutex);

        return NULL;
}

int
main(int argc, char const *argv[])
{
        long rc;
        size_t i, sec_p = 0;

        clock_t cl;
        pthread_t threads[NUM_THREADS];

        if (argc < 3)
        {
                printf("Faltan argumentos: N dimension del arreglo. \n");
                exit(-1);
        }

        N = atoi(argv[1]);
        NUM_THREADS = atoi(argv[2]);
        A = (size_t*) malloc(sizeof(size_t) * N);

        for (i = 0; i < NUM_THREADS; i++) {
                pthread_create(&threads[i], NULL, initialize, (void *)i);
        }

        for (i = 0; i < NUM_THREADS; i++)
        {
                rc = pthread_join(threads[i], NULL);
                #ifdef DEBUG
                printf("join() is %ld\n", threads[i]);
                #endif

                if (rc)
                {
                        printf("ERROR; return code from pthread_join() is %ld\n", rc);
                        exit(-1);
                }
        }

        cl = clock();

        for (i = 0; i < NUM_THREADS; i++)
        {
                pthread_create(&threads[i], NULL, counter, (void *)i);
        }

        for (i = 0; i < NUM_THREADS; i++)
        {
                rc = pthread_join(threads[i], NULL);
                #ifdef DEBUG
                printf("join() is %ld\n", threads[i]);
                #endif

                if (rc)
                {
                        printf("ERROR; return code from pthread_join() is %ld\n", rc);
                        exit(-1);
                }
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
