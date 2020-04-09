#include "shell.h"

int main ()
{
        char *line;
        char **argv;
        pid_t pid1;
        ssize_t line_chk = 0;
        size_t size = IP_SIZE;

        write(1, "$>", 3);
        line_chk = getline(&line, &size, stdin);

        while (strcmp(line, SH_KILLER) != 0)
        {
                if (line_chk == -1)
                        write(1, " ", 1);
                else
                        tokenizer(line, &argv);

        }
        printf("%s", argv[0]);
        return (0);
}
