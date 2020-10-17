/** pid.c **/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void){
	int pid;
	pid = getpid();

	printf("This process's pid: %d\n", pid);

	return (0);
}
