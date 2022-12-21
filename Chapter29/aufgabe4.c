#include "aufgabe1.h"
#include <pthread.h>
#include "common_threads.h"
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

list_t L;

void* worker(void* arg)
{
    // printf("\nThreadID: %d\n\n", (int) arg);
    for (size_t i = 0; i < 1000000; i++) // wird hier auf 1000001 erhöht, kommt anstatt 4000004 trotzdem 4000000 raus
    {
        //Pthread_mutex_lock(&L.lock);
        List_Insert(&L, i);
        //Pthread_mutex_unlock(&L.lock);
    }
    
    return NULL;
}

int main(int argc, char const *argv[])
{
    List_Init(&L);
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
    printf("4 Threads:\nTime needed (microsec): %li\n", time_needed);
    

    List_Init(&L);
    start = gettime();
    Pthread_create(&p5, NULL, worker, NULL);
    Pthread_join(p5, NULL);
    end = gettime();
    time_needed = end - start;
    printf("\n1 Thread:\nTime needed (microsec): %li\n", time_needed);
    return 0;
}
