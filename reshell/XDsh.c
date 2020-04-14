#include "shell.h"
#include <signal.h>
void sig_handler (int signal)
{
	(void) signal;
	exit(0);
}
int main (
	int ac __attribute__((unused)),
	char *av[] __attribute__((unused)),
	char *env[])
{
        char *line = NULL;
        char **argv;
        pid_t __attribute__((unused)) pid1;
        ssize_t line_chk = 0;
        size_t size = IP_SIZE;
	char *curpath, *path = "PATH";
	char *location;
	char **pathoken;
	int iter, fd;
	int status;
	caneca *head;
	head = NULL;
	location = malloc(256);
	add_nodeint_end(&head, location, NULL);
	if (!location)
		free_list(head, 0);
	signal(SIGINT, sig_handler);
        write(STDOUT_FILENO, "$", 1);
        line_chk = getline(&line, &size, stdin);
        while (_strcmp(line, SH_KILLER) != 0)
        {
		if (line_chk == -1)
		{
//			write(STDOUT_FILENO, "failed reading input\n", 22);
			free_list(head, 2);
		}
                if (line_chk > 0)
		{
//			printf("%s ->entring tokenizer\n", path);
			curpath = finds_path(env, path);
			pathoken = _strtok(curpath, &head);
			argv = _strtok(line, &head);
			fd = works_as_address (argv[0], argv, env);
			wait(NULL);
//			printf("getting location for %s\n", argv[0]);
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
		{
//			perror("cmd : command not found");
		}
		if (fd == 0)
			location = argv[0];
		pid1 = fork();
		if (pid1 == 0)
		{
//			printf("hijo!!!!!!!!!!\n");
			execve(location,argv,env);
		}
		else
			wait(NULL);
		write(STDOUT_FILENO, "$", 1);
		line_chk = getline(&line, &size, stdin);
	}
	add_nodeint_end(&head, line, NULL);
	free_list(head, 0);
//        printf("bye! bitches\n");
        return (0);
}
