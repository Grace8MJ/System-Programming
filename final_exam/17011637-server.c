/** 17011637-server.c **/

#include "fifo.h"
#include <ctype.h>

int main(){
	int sv_fifo_fd, cl_fifo_fd;
	int data_to_pass_int fifo_data;
	int read_res;
	char cl_fifo[256];

	mkfifo(SV_FIFO_NAME,0777);
	sv_fifo_fd = open(SV_FIFO_NAME, O_RDONLY);
	if (sv_fifo_fd == -1)
		exit(EXIT_FAILURE);

	while(1){
		read_res = read(sv_fifo,fd, &fifo_data, sizeof(fifo_data));
		if (read_res > 0){
			sprintf(cl_fifo, O_WRONLY);

			if (cl_fifo_fd != -1){
				sprintf("%d+1 = %d",fifo_data, fifo_data+1);
				write(cl_fifo_fd, &fifo_data, sizeof(fifo_data));
				close(cl_fifo_fd);
			}
		}
	}
	close(sv_fifo_fd);
	unlink(SV_FIFO_NAME);
	exit(EXIT_SUCCESS);
}
