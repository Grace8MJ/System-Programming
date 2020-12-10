#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define FIFO_NAME "17011637_c"

int main(void){
	char buf[100];
	int num, fd;

	// making a FD for FIFO
	if (mknod(FIFO_NAME, S_IFIFO | 0666, 0) == -1){
		perror("mknod error");
	}

	// we are waiting for a reader
	// we open the FD, when the reader opens the FD
	fd = open(FIFO_NAME, O_WRONLY);

	// send the user input data to the reader via FIFO
	while (fgets(num, sizeof(num), stdin), !feof(stdin)){
		if ((num = write(fd, num, strlen(num))) == -1)
			perror("write error");
		else
			printf("%d+1 = %d\n", num, num+1);
	}

	return 0;
}
