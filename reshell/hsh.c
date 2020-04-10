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
	char **pathoken;

	path = finds_path(env, path);

        write(STDIN_FILENO, "$>", 3);
        line_chk = getline(&line, &size, stdin);
	valid_simple_free(line, line_chk, 1);
        while (strcmp(line, SH_KILLER) != 0)
        {
                if (line_chk > 0)
		{
			printf("%s\n", path);
			printf("tokenizer entering\n");
			pathoken = tokenizer(path);
			printf("pathoken: %s\n", pathoken[1]);
                        argv = tokenizer(line);
			printf("argv: %s\n", argv[0]);
		}
		write(STDIN_FILENO, "$>", 3);
		line_chk = getline(&line, &size, stdin);
		valid_simple_free(line, line_chk, 1);
        }
	free(line);
        printf("bye! bitches\n");
        return (0);
}
