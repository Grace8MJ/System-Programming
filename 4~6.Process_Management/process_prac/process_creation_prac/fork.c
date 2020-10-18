/** fork.c **/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void){
	pid_t pid;

	printf("before fork(): %d\n", getpid());

	if ((pid = fork()) < 0)
		perror("error in fork()\n");
	
	else if (pid == 0){	// child process
		printf("hi! it's a child (%d -> %d)\n", getppid(), getpid());
	}

	else {	// parent process
		printf("hi! it's a parent (%d)\n", getpid());
	}

	// who's in charge of this?
	printf("after fork(): who called this? %d\n", getpid());

	exit(EXIT_SUCCESS);
}
