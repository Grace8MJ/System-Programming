/** rc_safe.c **/

int rc_safe(char *filename){
	struct stat st, st2;
	int fd;

	if (lstat(filename, &st) != 0)
		return -1;
	
	if (!S_ISREG(st.st_mode))	// if not regular file, exit program
		return -1;
	
	if (st.st_uid != 0)			// file owner ?= root
		return -1;
	fd = open(filename, O_RDWR, 0);
	if (fd < 0)
		return -1;

	if (fstat(fd, &st2) != 0){	// get info through st2
		close(fd);
		return -1;
	}

	if ((st.st_ino != st2.st_ino) || (st.st_dev != st2.st_dev)){
		close(fd);
		return -1;
	}
	return fd;
}
