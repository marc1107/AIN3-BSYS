#include "aufgabe1.h"
#include <pthread.h>
#include "common_threads.h"
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

#define BUCKETS (101)

typedef struct __hash_t {
    list_t lists[BUCKETS];
    pthread_mutex_t lock[BUCKETS];
} hash_t;

void Hash_Init(hash_t *H)
{
    for (int i = 0; i < BUCKETS; i++)
    {
        List_Init(&H->lists[i]);
        Pthread_mutex_init(&H->lock[i], NULL);
    }
}

int Hash_Insert(hash_t *H, int key)
{
    Pthread_mutex_lock(&H->lock[key % BUCKETS]);
    int re = List_Insert(&H->lists[key % BUCKETS], key);
    Pthread_mutex_unlock(&H->lock[key % BUCKETS]);
    return re;
}

int Hash_Lookup(hash_t *H, int key)
{
    Pthread_mutex_lock(&H->lock[key % BUCKETS]);
    int re = List_Lookup(&H->lists[key % BUCKETS], key);
    Pthread_mutex_unlock(&H->lock[key % BUCKETS]);
    return re;
}

hash_t H;

void* worker(void* arg)
{
    for (size_t i = 0; i < (long int) arg; i++)
    {
        Hash_Insert(&H, i);
    }
    
    return NULL;
}

int main(int argc, char const *argv[])
{
    Hash_Init(&H);
    pthread_t p1, p2, p3, p4, p5;
    long int start = gettime();
    Pthread_create(&p1, NULL, worker, (void *) 250000);
    Pthread_create(&p2, NULL, worker, (void *) 250000);
    Pthread_create(&p3, NULL, worker, (void *) 250000);
    Pthread_create(&p4, NULL, worker, (void *) 250000);
    Pthread_join(p1, NULL);
    Pthread_join(p2, NULL);
    Pthread_join(p3, NULL);
    Pthread_join(p4, NULL);
    long int end = gettime();
    long int time_needed = end - start;
    printf("4 Threads:\nTime needed (microsec): %li\n", time_needed);
    

    Hash_Init(&H);
    start = gettime();
    Pthread_create(&p5, NULL, worker, (void *) 1000000);
    Pthread_join(p5, NULL);
    end = gettime();
    time_needed = end - start;
    printf("\n1 Thread:\nTime needed (microsec): %li\n", time_needed);
    return 0;
}
