/** pipe3.c **/

// stdin = 0
// stdout = 1
// stderr = 2

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void){
	int pfd[2];

	if (pipe(pfd) == -1){
		perror("pipe error");
		exit(1);
	}

	if (!fork()){
		close(1);		// close the stdout (screen out)
		dup(pfd[1]);	// connect the stdout (screen out) with the pipe input
		close(pfd[0]);

		// now the result of the command ls goes into the pipe input
		execlp("ls", "ls", NULL);
	}
	else {
		close(0);		// close the stdin (keyboard input)
		dup(pfd[0]);	// connect the stdin with the pipe output
		close(pfd[1]);

		// pipe out becomes the input of the command wc
		execlp("wc", "wc", "-l", NULL);
	}

	return 0;
}
