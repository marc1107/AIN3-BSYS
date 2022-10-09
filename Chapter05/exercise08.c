#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	int pipefd[2];

	if (pipe(pipefd) == -1)
	{
		perror("pipe");
		exit(EXIT_FAILURE);
	}

	int rc = fork();
	if (rc < 0)
	{
		// fork failed
		fprintf(stderr, "fork failed\n");
		exit(1);
	} else if (rc == 0) {
		// child (new process)
		int w = wait(NULL);
	 	printf("Child wait(): %d\n", w);
    } else { 
		// parent goes down this path (main)
		int w = wait(NULL);
	 	printf("Parent wait(): %d\n", w);
    }
    return 0;
}

// wait() gibt die processID des childs zurück (wen nFehler dann -1)
// wird wait() im child aufgerufen, wird -1 (Fehler) zurückgegeben
