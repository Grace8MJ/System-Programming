/** wait.c **/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void){
	pid_t pid;
	int status;

	if ((pid = fork()) < 0)
		perror("fork error");

	else if (pid == 0) {	// child process
		printf("hi from child\n");
		exit(7);
	}

	else {	// parent process
		// parent process will wait until its child dies
		if (wait(&status) != pid)
			perror("wait error");
		printf("hi from parent\n");

		if (WIFEXITED(status))
			printf("normal, exit status = %d\n", WEXITSTATUS(status));
		else if (WIFSIGNALED(status))
			printf("abnormal, signal number = %d \n", WTERMSIG(status));
	}

	exit(EXIT_SUCCESS);
}
