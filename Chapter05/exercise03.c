#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void goodbye(int);

int main(int argc, char *argv[])
{
	// Process ID von parent sichern
	pid_t ppid = getpid();
	int rc = fork();
	if (rc < 0)
	{
		// fork failed
		fprintf(stderr, "fork failed\n");
		exit(1);
	} else if (rc == 0) {
		// child (new process)
		printf("hello\n");
		// SIGINT Signal an parent senden
		kill(ppid, SIGINT);
	} else { 
		// parent goes down this path (main)
		signal(SIGINT, goodbye);
		sleep(1);
		//printf("goodbye\n");
	}
	return 0;
}

void goodbye(int signal) {
	printf("goodbye\n");
}

// mit kill() und signal() erreicht man das gleiche Ergebnis wie mit wait()
