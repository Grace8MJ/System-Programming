/** 17011637-receive.c **/

#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void handler (int signo, siginfo_t *si){
	if (si->si_code == SI_QUEUE){
		printf("PID: %d\n", si->si_pid);
		printf("Signal Number: %d\n", si->si_signo);
		printf("User Data: %d\n", si->si_value.sival_int);
		getchar();
	}
	else {
		printf("Unix Standard Signal %d\n", signo);
	}
}

int main(){
	struct sigaction act;

	printf("My PID is %d\n", getpid());
	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_SIGINFO;
	act.sa_restorer = NULL;
	act.sa_sigaction = handler;

	if (sigaction(SIGTSTP, &act, NULL) == 1){
		printf("signal error\n");
		exit(0);
	}
	while (1){
		sleep(1);
	}
}
