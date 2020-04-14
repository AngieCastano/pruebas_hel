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
#include <signal.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
/**
 * struct caneca - recives address to free
 * @mugre: (malloc'ed pointer)
 * @next: points to the next node
 * Description: recives address to free
 */
typedef struct caneca
{
	char *mugre;
	char **mugre2;
	struct caneca *next;
} caneca;
char** tokenizer(char *line);
char *finds_path(char **env, char *path);
int str_cmp_first_chars(char *larga, char* peque);
char *_strcat(char *dest, char *src);
char* matcher(char *command, char* directory);
char** _strtok(char *av, caneca **h);
int com_c(char av, char delimiter[]);
caneca *add_nodeint_end(caneca **head, char *mugre, char **mugre2);
void print_listint(caneca *h);
void free_list(caneca *head, int retorno);
int _strcmp(char *s1, char *s2);
int works_as_address (char *argv0, char **argv, char *env[]);
void control_c(int sig);
void sig_handler(int signal);
#endif
