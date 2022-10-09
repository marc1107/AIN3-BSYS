#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	int rc = fork();
	if (rc < 0)
	{
		// fork failed
		fprintf(stderr, "fork failed\n");
		exit(1);
	} else if (rc == 0) {
		// child (new process)
		int w = waitpid(-1, NULL, 0);
	 	printf("Child wait(): %d\n", w);
    } else { 
		// parent goes down this path (main)
		int w = waitpid(-1, NULL, 0);
	 	printf("Parent wait(): %d\n", w);
    }
    return 0;
}

// hier waitpid(-1, NULL, 0) macht genau das gleiche wie wait(NULL)
// waitpid kann allerdings z.B. dazu verwendet werden auf ein child 
// zu warten das eine bestimmte process ID oder process group ID hat
// aktuell wird in Z. 16 auf irgendeinen child process gewartet (wie bei wait())
