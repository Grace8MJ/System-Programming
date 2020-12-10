/** fifo.h **/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/stat.h>

#define SV_FIFO_NAME "./17011637_s"
#define CL_FIFO_NAME "./17011637_c"

int data_to_pass_int;
