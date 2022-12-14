#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	int x = 100;
	int rc = fork();
	if (rc < 0)
	{
		// fork failed
		fprintf(stderr, "fork failed\n");
		exit(1);
	} else if (rc == 0) {
		// child (new process)
	 	printf("x child: %d\n", x);
		x = 20;
	 	printf("x child after change: %d\n", x);
    } else { 
		// parent goes down this path (main)
        printf("x parent: %d\n", x);
		x = 300;
        printf("x parent after change: %d\n", x);
    }
    return 0;
}

// Variable x hat im child process trotzdem noch den Wert 100,
// obwohl im parent process x schon auf 300 gesetzt wurde