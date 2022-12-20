#include "aufgabe1.h"
#include <pthread.h>
#include "common_threads.h"
#include <stdio.h>
#include <sys/syscall.h>

#define NUMCPUS 4

typedef struct __counter_t {
    int global;
    pthread_mutex_t glock;
    int local[NUMCPUS];
    pthread_mutex_t llock[NUMCPUS];
    int threshold;
} counter_t;

counter_t c;

void init(counter_t *c, int threshhold)
{
    c->threshold = threshhold;
    c->global = 0;
    Pthread_mutex_init(&c->glock, NULL);
    for (int i = 0; i < NUMCPUS; i++)
    {
        c->local[i] = 0;
        Pthread_mutex_init(&c->llock[i], NULL);
    }
}

void update(counter_t *c, int threadID, int amt)
{
    int cpu = threadID % NUMCPUS;
    Pthread_mutex_lock(&c->llock[cpu]);
    c->local[cpu] += amt;
    if (c->local[cpu] >= c->threshold)
    {
        pthread_mutex_lock(&c->glock);
        c->global += c->local[cpu];
        pthread_mutex_unlock(&c->glock);
        c->local[cpu] = 0;
    }
    Pthread_mutex_unlock(&c->llock[cpu]);
}

int get(counter_t *c)
{
    Pthread_mutex_lock(&c->glock);
    int re = c->global;
    Pthread_mutex_unlock(&c->glock);
    return re;
}

void* worker(void* arg)
{
    // printf("\nThreadID: %d\n\n", (int) arg);
    for (size_t i = 0; i < 1000000; i++) // wird hier auf 1000001 erhöht, kommt anstatt 4000004 trotzdem 4000000 raus
    {
        update(&c, (long int) arg, 1);
    }
    
    return NULL;
}

int main(int argc, char const *argv[])
{
    init(&c, 5);
    pthread_t p1, p2, p3, p4, p5;
    long int start = gettime();
    Pthread_create(&p1, NULL, worker, (void* ) 0);
    Pthread_create(&p2, NULL, worker, (void* ) 1);
    Pthread_create(&p3, NULL, worker, (void* ) 2);
    Pthread_create(&p4, NULL, worker, (void* ) 3);
    Pthread_join(p1, NULL);
    Pthread_join(p2, NULL);
    Pthread_join(p3, NULL);
    Pthread_join(p4, NULL);
    long int end = gettime();
    long int time_needed = end - start;
    printf("4 Threads:\nCounter: %d\nTime needed (microsec): %li\n", get(&c), time_needed);

    init(&c, 5);
    start = gettime();
    Pthread_create(&p5, NULL, worker, (void* ) 5);
    Pthread_join(p5, NULL);
    end = gettime();
    time_needed = end - start;
    printf("\n1 Thread:\nCounter: %d\nTime needed (microsec): %li\n", get(&c), time_needed);
    return 0;
}
