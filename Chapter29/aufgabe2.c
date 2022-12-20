#include "aufgabe1.h"
#include <pthread.h>
#include "common_threads.h"
#include <stdio.h>

typedef struct __counter_t {
    int value;
    pthread_mutex_t lock;
} counter_t;

counter_t c;

void init(counter_t *c)
{
    c->value = 0;
    Pthread_mutex_init(&c->lock, NULL);
}

void increment(counter_t *c)
{
    Pthread_mutex_lock(&c->lock);
    c->value++;
    Pthread_mutex_unlock(&c->lock);
}

void decrement(counter_t *c)
{
    Pthread_mutex_lock(&c->lock);
    c->value--;
    Pthread_mutex_unlock(&c->lock);
}

int get(counter_t *c)
{
    Pthread_mutex_lock(&c->lock);
    int re = c->value;
    Pthread_mutex_unlock(&c->lock);
    return re;
}

void* worker(void* arg)
{
    for (size_t i = 0; i < 1000000; i++)
    {
        increment(&c);
    }
    
    return NULL;
}

int main(int argc, char const *argv[])
{
    init(&c);
    pthread_t p1, p2, p3, p4, p5;
    long int start = gettime();
    Pthread_create(&p1, NULL, worker, NULL);
    Pthread_create(&p2, NULL, worker, NULL);
    Pthread_create(&p3, NULL, worker, NULL);
    Pthread_create(&p4, NULL, worker, NULL);
    Pthread_join(p1, NULL);
    Pthread_join(p2, NULL);
    Pthread_join(p3, NULL);
    Pthread_join(p4, NULL);
    long int end = gettime();
    long int time_needed = end - start;
    printf("4 Threads:\nCounter: %d\nTime needed (microsec): %li\n", get(&c), time_needed);

    init(&c);
    start = gettime();
    Pthread_create(&p5, NULL, worker, NULL);
    Pthread_join(p5, NULL);
    end = gettime();
    time_needed = end - start;
    printf("\n1 Thread:\nCounter: %d\nTime needed (microsec): %li\n", get(&c), time_needed);
    return 0;
}
