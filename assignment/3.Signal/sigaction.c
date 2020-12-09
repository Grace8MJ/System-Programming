/** sigaction.c **/

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>

volatile sig_atomic_t stop;

void handler(int signo){
	psignal(signo, "Received signal");
	sleep(5);
	stop = 1;
}

int main(void){
	struct sigaction act;
	
	sigemptyset(&act.sa_mask);
	sigaddset(&act.sa_mask, SIGQUIT);
	act.sa_handler = handler;
	act.sa_flags = 0;
	
	sigaction(SIGTSTP, &act, NULL);

	while(!stop);

	return 0;
}
