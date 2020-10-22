/** exec2.c **/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void){
	pid_t pid;

	pid = fork();

	switch(pid){
		case -1: 
			perror ("fork() failed\n");
			break;
		case 0:	// child process
			printf("child: execl() executing ls beginning\n");
			execl("/bin/ls", "ls", "-l", (char *)0);
			perror("execl() failed\n");
			break;
		default:	// parent process
			wait((int *)0);	// parent wait until child dies
			printf("parent: execl() executing ls completed\n");
			exit(0);
	}
	return (0);
}
