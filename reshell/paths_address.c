#include "shell.h"
int works_as_address (char *argv0, char **argv, char *env[])
{
	int fd, forky;
	fd = open(argv0 ,O_RDONLY);
//	printf("p : %i\n", fd);
	if (fd == 3)
	{
		close(fd);
		return(0);
	}
	close(fd);
	return (-1);
}
