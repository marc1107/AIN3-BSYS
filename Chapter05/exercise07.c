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
		printf("Closing STDOUT_FILENO\n");
		close(STDOUT_FILENO);
		printf("Test\n");
    } else { 
		// parent goes down this path (main)
		wait(NULL);
	 	printf("Parent\n");
    }
    return 0;
}

// child kann nicht mehr auf die Standardausgabe ausgeben wenn STDOUT_FILENO geclosed wurde
