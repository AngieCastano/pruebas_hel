#include "shell.h"

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
char* matcher(char *command, char* directory)
{
	struct dirent *pDirent;
	DIR *pDir;
	char* path = "\n";

	pDir = opendir(directory);
	if (pDir == NULL)
	{
		printf ("Cannot open directory '%s'\n", directory);
		return (NULL);
	}
	while ((pDirent = readdir(pDir)) != NULL) {
		if (_strcat(command, path) == pDirent->d_name)
		{
			path = pDirent->d_name;
			printf("path: %s\n", path);
			_strcat(directory, path);
			printf("directory: %s\n", directory);
			closedir (pDir);
			return (directory);
		}
		else
			printf(".");
	}
	closedir (pDir);
	directory = NULL;
	return (directory);
}
