/** system.c **/
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include "ours.h"

extern int n_system(const char *cmd);

// several commands such as grep, cut, pipelines
char *cmd = "grep hurryon /etc/passwd | cut -f 5 -d:";

int main(void){
	int status;
	if ((status = n_system(cmd)) == -1)
		perror("n_system() error");

	print_exit(status);

	exit(EXIT_SUCCESS);
}
