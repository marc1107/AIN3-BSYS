#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

int main(int argc, char* argv[]) {
    printf("Pid: %d\n", getpid());

    if (argc < 3) {
        printf("Falsches Eingabeformat\n");
        exit(1);
    }
    int bytes = atoi(argv[1]) * 1024 * 1024;
    int arrayLength = (int) (bytes / sizeof(int));
    int runtime = atoi(argv[2]);
    int* array = malloc(bytes); // Jeder Integer nimmt 4 Byte Platz
    clock_t start = clock();

    if (array <= 0) {
        printf("Malloc Fehler\n");
        exit(1);
    }

    while(1)
    {
        if ((double)(clock() - start) / CLOCKS_PER_SEC >= runtime)
        {
            break;
        }
        
        for (size_t i = 0; i < arrayLength; i++)
        {
            array[i] = 1;
        }
    }

    free(array);
    printf("Programm beendet\n");

    return 0;
}