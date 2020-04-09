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
	char *path = "PATH";

	path = finds_path(env, path);

        write(STDIN_FILENO, "$>", 3);
        line_chk = getline(&line, &size, stdin);

        while (strcmp(line, SH_KILLER) != 0)
        {
                if (line_chk == -1)
		{
                        write(STDIN_FILENO, "failed reading input\n", 22);
			exit (0);
		}
                if (line_chk > 0)
		{
			printf("%s\n", path);
			printf("tokenizer entering\n");
                        argv = tokenizer(line);
			printf("%s\n", argv[0]);
		}
		write(STDIN_FILENO, "$>", 3);
		line_chk = getline(&line, &size, stdin);
        }
        printf("bye! bitches\n");
        return (0);
}
