/** exec-env.c **/

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include "ours.h"

char *env_init [] = {"USER=unknown", "TERM=xterm", NULL};

char first[] = "=== first fork() child ====\n";
char second[] = "=== second fork() child ===\n";

int main(void){
	pid_t pid;

	//first fork()
	if ((pid = fork()) <0){
		perror("fork error");
	}

	//child
	else if (pid == 0){
		write(STDOUT_FILENO, first, strlen(first));
		if (execle("./print-env", "print-env", "jong-hyouk", "lee", NULL, env_init) < 0)
			perror("execle error");
	}

	//parent waiting for child to die
	if (wait(NULL) < 0)
		perror ("wait error");

	// second fork()
	if ((pid = fork()) <0)
		perror("fork error");

	// child
	else if (pid == 0){
		write(STDOUT_FILENO, second, strlen(second));
		if (execlp("./print-env", "print-env", "one argument", NULL) < 0)
			perror("execlp error");
	}
	exit(EXIT_SUCCESS);
}
