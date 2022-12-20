#include <stdio.h>
#include <sys/time.h>
#include "aufgabe1.h"

long int gettime()
{
    struct timeval current_time;
    gettimeofday(&current_time, NULL);
    long int time_in_micro = current_time.tv_sec * 1000000 + current_time.tv_usec;
    return time_in_micro;
}
