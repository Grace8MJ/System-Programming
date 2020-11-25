/** zombie.c **/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
	pid_t pid;
	
	for (int i=0; i<5; i++){
		if ((pid = fork()) < 0)	// try to create child process
			perror("fork error");

		else if (pid == 0) {	// child process
			printf("Child PID: %d, Parent PID: %d\n", getpid(), getppid());
			exit(EXIT_SUCCESS);
		}
		// parent does nothing but child process is alive
	}

	// child process becomes zombie process (check by ps -ef)
	sleep(100);

	printf("Bye from Parent process\n");
	exit(EXIT_SUCCESS);
}
