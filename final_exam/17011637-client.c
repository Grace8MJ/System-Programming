/** 17011637-client.c **/

#include "fifo.h"
#include <ctype.h>

int main(){
	int sv_fifo_fd, cl_fifo_fd;
	int data_to_pass_int fifo_data;

	char cl_fifo[256];

	sv_fifo_fd = open(SV_FIFO_NAME, O_WRONLY);
	if(sv_fifo_fd == 1)
		exit(EXIT_FAILURE);

	sprintf(cl_fifo,CL_FIFO_NAME, fifo_data);
	if(mkfifo(cl_fifo, 0777) == -1)
			exit(EXIT_FAILURE);
	write(sv_fifo_fd, &fifo_data, sizeof(fifo_data));
	cl_fifo_fd = open(cl_fifo, O_RDONLY);
	if (cl_fifo_fd != -1){
		if (read(cl_fifo_fd, &fifo_data, sizeof(fifo_data)) >0){}
		close(cl_fifo_fd);
	}
	close(sv_fifo_fd);
	unlink(cl_fifo);
	exit(EXIT_SUCCESS);
}
