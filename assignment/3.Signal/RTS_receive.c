/** RTS_receive.c **/

#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void handler(int signo, siginfo_t *si){
	if (si->si_code == SI_QUEUE){
		printf("User RTS signal %d\n", si->si_pid);
		printf("Sig Number %d\n", si->si_signo);
		printf("User Data is %d\n", si->si_value.sival_int);
		getchar();
	}
	else {
		printf("Get none RTS %d\n", signo);
	}
}

int main(){
	struct sigaction act;

	printf("My PID %d\n", getpid());

	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_SIGINFO;
	act.sa_restorer = NULL;
	act.sa_sigaction = handler;

	if (sigaction(SIGRTMIN, &act, NULL) == 1){
		printf("signal error\n");
		exit(0);
	}
	while (1){
		sleep(1);
	}
}
