#ifndef SHELL_H
#define SHELL_H
#define IP_SIZE 200
#define SH_KILLER "quit\n"
#define DELIMITER "=: \n"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>
char** tokenizer(char *line);
char *finds_path(char **env, char *path);
int str_cmp_first_chars(char *larga, char* peque);
void escoba_double(char **recogedor, int fallos);
void valid_simple_free(char *recogedor, ssize_t line_chk, int exit1);
char *_strcpy(char *dest, char *src);
#endif
