#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void){
	pid_t pid;
	int status = 0;

	if ((pid = fork()) == 0){	// fork() to create child process
		printf("Child PID is %d, Parent PID is %d.\n", getpid(), getppid());	// getpid() to print own pid, getppid() to print pid of parent process
		return 0;
	}

	else{
		while (!waitpid(pid, &status, WNOHANG));	// waitpid() to make parent process print pid of parent process (not systemd)
		printf("Parent PID is %d\n", getpid());
	}
	return 0;
}
