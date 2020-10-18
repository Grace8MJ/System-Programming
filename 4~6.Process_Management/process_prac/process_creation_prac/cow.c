/** cow.c **/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int global = 100;	// initialized data

int main(void){
	int var;	// automatic variable, local variable in the stack
	pid_t pid;

	var = 10;

	if ((pid = fork()) < 0)
		perror("error in fork()\n");

	// child process
	else if (pid == 0){
		printf("hi! it's a child (%d)\n", getpid());
		global++;
		var++;
	}

	// parent process
	else{
		sleep(3);
		printf("hi! it's a parent (%d)\n", getpid());
	}

	// individual parts for the child and parent process
	printf("pid: %d, global: %d, var: %d\n", getpid(), global, var);

	exit(EXIT_SUCCESS);
}
