#include <stdio.h>

int str_cmp_first_chars(char *larga, char* peque)
{
	int i = 0, j = 0;
	for(i = 0; peque[i]; i++)
	{
	}
	for(j = 0; peque[j]; j++)
	{
		if(larga[j] != peque[j])
			break;
	}
	if (i == j)
		return(1);
	else
		return (0);
}

char *finds_path(char *env[], char *path)
{
	int prim_chars = 0;
	int i = 0;

	for(i = 0; env[i]; ++i)
	{
		if ((prim_chars = str_cmp_first_chars(env[i], path)) == 1)
		break;
	}
	return (env[i]);
}
