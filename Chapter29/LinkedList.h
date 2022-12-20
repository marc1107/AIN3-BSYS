#ifndef linkedlist_h
#define linkedlist_h

#include <pthread.h>

typedef struct __node_t {
    int key;
    struct __node_t *next;
    pthread_mutex_t lock;
} node_t;

typedef struct __list_t {
    node_t *head;
    pthread_mutex_t lock;
} list_t;

void List_Init(list_t *L);
int List_Insert(list_t *L, int key);
int List_Lookup(list_t *L, int key);
int List_Delete(list_t *L, int key);

#endif
