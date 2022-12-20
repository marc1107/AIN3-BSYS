#include "LinkedList.h"
#include "aufgabe1.h"
#include <pthread.h>
#include "common_threads.h"
#include <stdio.h>
#include <stdlib.h>

void List_Init(list_t *L)
{
    L->head = NULL;
    Pthread_mutex_init(&L->lock, NULL);
}

int List_Insert(list_t *L, int key)
{
    int re = 0;
    node_t *new = malloc(sizeof(node_t));
    Pthread_mutex_init(&new->lock, NULL);
    if (new == NULL)
    {
        perror("malloc");
        return re;
    }
    Pthread_mutex_lock(&L->lock);
    // Lock für new wird nicht benötigt
    /*if (L->head)
    {
        Pthread_mutex_lock(&L->head->lock);
    }*/

    // wie kann man das lösen ohne die ganze Liste zu sperren und trotzdem keine Fehler in helgrind zu bekommen?
    
    new->next = L->head;
    L->head = new;
    //Pthread_mutex_unlock(&L->head->lock);
    Pthread_mutex_unlock(&L->lock);
    re = 1;
    return re;
}

int List_Lookup(list_t *L, int key) {
    int re = 0;
    // Pthread_mutex_lock(&L->lock);
    Pthread_mutex_lock(&L->head->lock);
    node_t *curr = L->head;
    node_t *tmp = NULL;
    while (curr)
    {   
        if(curr->key == key) {
            re = 1;
            break;
        }
        tmp = curr;

        if (curr->next)
        {
            Pthread_mutex_lock(&curr->next->lock);
        }
        curr = curr->next;
        Pthread_mutex_unlock(&tmp->lock);
    }
    
    // Pthread_mutex_unlock(&L->lock);
    return re;
}

int List_Delete(list_t *L, int key) {
    int re = 0;
    //Pthread_mutex_lock(&L->lock);
    Pthread_mutex_lock(&L->head->lock);
    node_t *current = L->head;
    node_t *tmp1 = NULL;
    while(current && current->key != key) {
        if (tmp1)
        {
            Pthread_mutex_unlock(&tmp1->lock);
        }
        tmp1 = current;
        Pthread_mutex_lock(&current->next->lock);
        current = current->next;
    }

    if (current)
    {
        Pthread_mutex_lock(&current->next->lock);
        tmp1->next = current->next;
        Pthread_mutex_unlock(&tmp1->lock);
        Pthread_mutex_unlock(&current->next->lock);
        Pthread_mutex_unlock(&current->lock);
        free(current);
        re = 1;
    }
    
    //Pthread_mutex_unlock(&L->lock);
    return re;
}
