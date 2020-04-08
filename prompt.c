#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include<sys/wait.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>
/**
 * _strcat - concayenating 2 strings
 * @dest: where both string become 1
 * @src: string to add to de dest
 * Return: concatenated strings
 */

char *_strcat(char *dest, char *src)
{
	int i, j;

	for (i = 0; dest[i] != '\0'; i++)
	{
	}
	for (j = 0; src[j] != '\0'; j++)
		dest[i + j] = src[j];
	return (dest);
}
char* matching_name_in_directory(char *command, char* directory)
{
	struct dirent *pDirent;
	DIR *pDir;
	char* path;

	pDir = opendir(directory);
	if (pDir == NULL)
	{
		printf ("Cannot open directory '%s'\n", directory);
		return (NULL);
	}
	while ((pDirent = readdir(pDir)) != NULL) {
		if (command == pDirent->d_name)
		{
			path = pDirent->d_name;
			printf("path: %s\n", path);
			_strcat(directory, path);
			printf("directory: %s\n", directory);
		}
		printf("pDirent->d_name %s\n", pDirent->d_name);
	}
	closedir (pDir);
	return (directory);
}

int main()
{

	char *buffer, *token;
	char **args;
	size_t size = 0;
	ssize_t rtrngetline = 1;
	int i = 0, j = 0;
	pid_t pid1 = 1;
	char* directorio_final;

	while (rtrngetline != -1)
	{
		write(1, "$ ", 2);
		rtrngetline = getline(&buffer,&size,stdin);
		token = strtok(buffer, " ");
		args[0] = token;

		if (args[i])
		{
			for(j = 0; args[i][j]; j++)
			{
			}
			j--;
		}
		args[i][j] = '\0';
		printf("args[0] %s\n", args[0]);
		while (token)
		{
			printf("token : %s\n", token);
			token = strtok(NULL, " ");
			i++;
			args[i] = token;
			if (args[i])
			{
				for(j = 0; args[i][j]; j++)
				{
				}
				j--;
				args[i][j] = '\0';
			}
			printf("args[%i] %s\n",i, args[i]);
//			printf("rtrngetline: %li", rtrngetline);
		}
		printf("args[0] %s\n", args[0]);
		i = 0;
		directorio_final =  matching_name_in_directory(args[0], "/bin");
		pid1 = fork();
		waitpid(pid1, NULL, 0);
		if (pid1 == 0)
		{
			execve(directorio_final,args,NULL);
//			printf("hijo 1\n");
		}
//		printf("hijo 1\n");
//		else
//		{
//			waitpid(pid1, NULL, 0);
//			printf("padre1\n");
//		}
	}
	return (0);
}
