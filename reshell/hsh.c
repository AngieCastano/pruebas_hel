#include "shell.h"

int main ()
{
        char *line = NULL;
        char **argv;
        pid_t pid1;
        ssize_t line_chk = 0;
        size_t size = IP_SIZE;

        write(STDIN_FILENO, "$>", 3);
        line_chk = getline(&line, &size, stdin);

        while (strcmp(line, SH_KILLER) != 0)
        {
                if (line_chk == -1)
                        write(STDIN_FILENO, "failed reading input", 21);
                if (line_chk > 0)
		{
			printf("tokenizer entering\n");
                        argv = tokenizer(line);
			printf("%s\n", argv[0]);
		}
		write(STDIN_FILENO, "$>", 3);
		line_chk = getline(&line, &size, stdin);
        }
        printf("%s", argv[0]);
        return (0);
}
