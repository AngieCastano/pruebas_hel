#include "shell.h"
#include <signal.h>
void sig_handler (int signal)
{
	write(STDOUT_FILENO, "\n$", 2);
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
//		write(STDOUT_FILENO, "$", 1);
//		line_chk = getline(&line, &size, stdin);
		if (line_chk == -1)
		{
//			write(STDOUT_FILENO, "failed reading input\n", 22);
			free_list(head, 2);
		}
		/* si fd falla*/
                if (line_chk > 0)
		{
//			printf("%s ->entring tokenizer\n", path);
			curpath = finds_path(env, path);
			pathoken = _strtok(curpath, &head);
			argv = _strtok(line, &head);
			fd = works_as_address (argv[0], argv, env);
			if (fd != 0)
			{

				location = NULL;
				for (iter = 1; pathoken[iter]; iter++)
				{
					location = matcher(argv[0], pathoken[iter]);
					if (location != NULL)
						break;
				}
				iter = 1;
			}
		}
		if (fd == 0)
			location = argv[0];
		if (location != NULL)
		{
			pid1 = fork();
			if (pid1 == 0)
			{
				execve(location,argv,env);
			}
			else
				wait(NULL);
		}
		else
			printf("No me mandes basura pinche humano!\n");
		write(STDOUT_FILENO, "$", 1);
		line_chk = getline(&line, &size, stdin);
	}
	add_nodeint_end(&head, line, NULL);
	free_list(head, 0);
//        printf("bye! bitches\n");
        return (0);
}
