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
	 	printf("Calling exec\n");
		char *binaryPath = "/bin/ls";
		char *arg1 = "-lh";
		char *arg2 = "/home";
		char *command = "ls";
		char *args[] = {binaryPath, arg1, arg2, NULL};
		char *args2[] = {command, arg1, arg2, NULL};
		
		execl(binaryPath, binaryPath, arg1, arg2, NULL); // benötigt den kompletten Pfad (/bin/ls)
		//execlp(command, command, arg1, arg2, NULL); // kann den Pfad aus den Umgebungsvariablen nehmen
		//execv(binaryPath, args); // benötigt kompletten Pfad aber args können als Array übergeben werden
		//execvp(command, args2); // nimmt Umgebungsvariable und args kann als Array übergeben werden
		// bei execle bzw execve können dann noch eigene Umgebungsvariablen übergeben werden
		// Quelle: https://linuxhint.com/exec_linux_system_call_c/
    } else { 
		// parent goes down this path (main)
	printf("goodbye\n");
    }
    return 0;
}
