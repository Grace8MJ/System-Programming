#include <stdio.h>
#include <unistd.h>

int main(void){
	pid_t pid;
	int status;

	if((pid=fork()) == 0)
		execl("/bin/ls", "ls", 0);

	wait(&status);
	printf("'execl function execution'\n");

	return 0;
}
