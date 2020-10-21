/** wait2.c **/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "ours.h"

int main(void){
	pid_t pid;
	int status;

	/* ----- 1st fork ----- */
	if ((pid = fork()) < 0) 
		perror("fork error");
	else if (pid == 0) 
		exit(7); // child process exit with signal no. 7

	// parent waits for child process's death
	if (wait(&status) != pid) 
		perror("wait error");
	print_exit(status);	// parent calls print_exit func to know how the child died

	/* ----- 2nd fork ------ */
	if ((pid = fork()) < 0) 
		perror("fork error");
	else if (pid == 0)
		abort();	// child process calls abort (abnormal termination)

	// parent waits for child process's death
	if (wait(&status) != pid) 
		perror("wait error");
	print_exit(status);	// parent calls print_exit

	/* ----- 3rd fork ----- */
	if ((pid == fork()) < 0) 
		perror("fork error");
	else if (pid == 0)
		status /= 0;	// child process does sth wrong

	// parent waits for child process's death
	if (wait(&status) != pid) 
		perror("wait error");
	print_exit(status);	// parent calls print_exit

	exit(EXIT_SUCCESS);
}
