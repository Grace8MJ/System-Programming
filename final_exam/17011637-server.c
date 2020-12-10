#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define FIFO_NAME "17011637_s"

int main(void){
	char buf[100];
	int num, fd;

	// making a FD, which is the same one the writer uses, for FIFO
	if (mknod(FIFO_NAME, S_IFIFO | 0666, 0 ) == -1)
		perror("mknod error");

	// we are waiting for the writer
	// we open the FD, when the writer opens the FD
	fd = open(FIFO_NAME, O_RDONLY);

	// Receive the data sent from the writer via FIFO
	do{
		if ((read(fd, num, strlen(num))) == -1)
			perror("read error");
		else{
			printf("%d\n",num);
		}
	}while (num > 0);

	return 0;
}
