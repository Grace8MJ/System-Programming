/** rc_tmp.c **/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char *argv[]){
	struct stat st;
	FILE * fp;
	if (argc != 3){
		fprintf(stderr, "usage: %s file message\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	sleep(20);		// race condition attack

	if ((fp = fopen(argv[1], "w")) == NULL){
		fprintf(stderr, "Can't open\n");
		exit(EXIT_FAILURE);
	}
	fprintf(fp, "%s\n", argv[2]);
	fclose(fp);
	fprintf(stderr, "Write OK\n");
	exit(EXIT_SUCCESS);
}
