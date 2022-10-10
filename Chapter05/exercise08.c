#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	int pipefd[2];
	pid_t cpid;
	char buf;

	cpid = fork();
	if (cpid < 0)
	{
		// fork failed
		fprintf(stderr, "fork failed\n");
		exit(1);
	} else if (cpid == 0) {
		// child (new process)
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
			// second child
			//printf("Child 2\n");

			close(pipefd[1]);          /* Close unused write end */

			while (read(pipefd[0], &buf, 1) > 0)
            	write(STDOUT_FILENO, &buf, 1);

        	write(STDOUT_FILENO, "\n", 1);
            close(pipefd[0]);
			_exit(EXIT_SUCCESS);
		} else {
			// first child
			//printf("Child 1\n");

			close(pipefd[0]);          /* Close unused read end */
            write(pipefd[1], argv[1], strlen(argv[1]));
            close(pipefd[1]);          /* Reader will see EOF */
            wait(NULL);                /* Wait for child */
            exit(EXIT_SUCCESS);
		}
    } else { 
		// parent goes down this path (main)
	 	//printf("Parent\n");
    }
    return 0;
}

// wait() gibt die processID des childs zurück (wen nFehler dann -1)
// wird wait() im child aufgerufen, wird -1 (Fehler) zurückgegeben
