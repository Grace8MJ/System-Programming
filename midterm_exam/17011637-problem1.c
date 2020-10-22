/** 17011637-problem1.c **/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void){
	pid_t pid;

	if ((pid = fork()) < 0)
		perror("error in fork()\n");
	
	else if (pid == 0){	// child process
		printf("Child PID is %d, Parent PID is %d.\n", getpid(), getppid());
	}

	else {		// parent process
		wait((int *)0);
		printf("Parent PID is %d\n", getpid());
	}

	exit(EXIT_SUCCESS);
}
