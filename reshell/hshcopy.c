#include "shell.h"

int main (
	int ac __attribute__((unused)),
	char *av[] __attribute__((unused)),
	char *env[]
	)
{
        char *line = NULL;
        char **argv;
        pid_t __attribute__((unused)) pid1;
        ssize_t line_chk = 0;
        size_t size = IP_SIZE;
	char *curpath, *path = "PATH";
	char *location = malloc(256);
	char **pathoken;
	int iter;

        write(STDOUT_FILENO, "$", 1);
        line_chk = getline(&line, &size, stdin);

        while (strcmp(line, SH_KILLER) != 0)
        {
                if (line_chk == -1)
		{
                        write(STDOUT_FILENO, "failed reading input\n", 22);
			free(line);
			exit (0);
		}
                if (line_chk > 0)
		{
			printf("%s ->entring tokenizer\n", path);
			curpath = finds_path(env, path);
			pathoken = _strtok(curpath);
                        argv = _strtok(line);
			printf("getting location for %s\n", argv[0]);
			location = NULL;
			for (iter = 1; pathoken[iter]; iter++)
			{
				location = matcher(argv[0], pathoken[iter]);
				if (location != NULL)
					break;
			}
			iter = 1;
		}
		if (location == NULL)
			perror("cmd unknown\n");
		else
		{
			pid1 = fork();
			if (pid1 == 0)
			{
				execve(location,argv,NULL);
			}
			else
				waitpid(pid1, NULL, 0);
		}
		write(STDOUT_FILENO, "$", 1);
		line_chk = getline(&line, &size, stdin);
        }
	free(line);
        printf("bye! bitches\n");
        return (0);
}
