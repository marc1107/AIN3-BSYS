#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
	int fd = open("./testfile.txt", O_CREAT|O_WRONLY|O_TRUNC, S_IRWXU);
	int rc = fork();
	if (rc < 0)
	{
		// fork failed
		fprintf(stderr, "fork failed\n");
		exit(1);
	} else if (rc == 0) {
		// child (new process)
	 	printf("file child: %d\n", fd);
		write(fd, 1, 1);
    } else { 
		// parent goes down this path (main)
        printf("file parent: %d\n", fd);
		write(fd, 1, 2);
    }
    return 0;
}

// Ja, parent und child können beide auf den descriptor zugreifen
// 
