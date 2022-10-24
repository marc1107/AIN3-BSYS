#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

int main(int argc, char* argv[]) {
    if (argc < 3) {
        printf("Falsches Eingabeformat\n");
        exit(1);
    }
    int megabytes = atoi(argv[1]);
    int bytes = megabytes * pow(10, 6);
    int arrayLength = bytes / sizeof(int);
    int runtime = atoi(argv[2]);
    int* array = malloc(arrayLength); // Jeder Integer nimmt 4 Byte Platz
    clock_t start = clock();

    if (array <= 0) {
        printf("Malloc Fehler\n");
        exit(1);
    }

    while(1)
    {
        if ((clock() - start) / CLOCKS_PER_SEC >= runtime)
        {
            break;
        }
        
        for (size_t i = 0; i < arrayLength; i++)
        {
            int a = array[i];
            //array[i] = 1;
        }
    }

    printf("Programm beendet\n");

    return 0;
}