/** 17011637-problem2.c **/

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>

volatile sig_atomic_t stop;

void handler(int signo){
	if (signo == 2) {	// SIGINT
		psignal(signo, "Received Signal:");
	}
	else if (signo == 20) {	// SIGTSTP
		psignal(signo, "Received Signal:");
	}
	else if (signo == 3) {	// SIGQUIT
		stop = 1;
	}
}

int main(void){
	struct sigaction act;
	int cnt = 0;

	sigemptyset(&act.sa_mask);
	sigaddset(&act.sa_mask, SIGQUIT);
	sigaddset(&act.sa_mask, SIGINT);
	sigaddset(&act.sa_mask, SIGTSTP);
	act.sa_handler = handler;
	act.sa_flags = 0;

	sigaction(SIGTSTP, &act, NULL);
	sigaction(SIGINT, &act, NULL);
	sigaction(SIGTSTP, &act, NULL);

	while(!stop){
		printf("Waiting for signal to be received! Count:%d\n",cnt);
		cnt++;
		sleep(1);
	}
	return 0;
}
