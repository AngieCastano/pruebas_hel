#include <stdio.h>
#include <stdlib.h>
#include "shell.h"
/**
 * com_c - compares a char with many chars at the same tiime
 * @av: char to compare
 * @delimiter: array of chars ot compare
 * Return: 1 if the char is equal to one delimiter, 0 if av is never equal
 */
int com_c(char av, char delimiter[])
{
	int i = 0;
	if (!av)
		return(1);
	for(i = 0; delimiter[i]; i++)
		if (av == delimiter[i])
			return(1);
	return(0);
}
/**
 * _strtok - from a string creates a matrix of strings, splited by delimiters.
 * @av: string to split
 * Return: a matrix of strings splited by delimiters
 */
//char** _strtok(char *av, char del[])
int main()
{
	char* av = "PATH:bin/usr/bin:sadmin/usr/local:/suser";
	if(!av)
		return(0);
	int j = 0, i = 0, palabras = 1, k = 0;
	char **arr_palabs;
	char del[] = {':','\n',' ','='};
	for (i = 0; av[i]; i++)
	{
		if((com_c(av[i],del) == 1) && (com_c(av[i - 1],del) == 0))
		{
			palabras++;
		}
	}
	arr_palabs = malloc((palabras + 1) * sizeof(char *));
	arr_palabs[palabras] = NULL;
	palabras = 0;
	for (i = 0; av[i]; i++)
	{
		if ((com_c(av[i],del)) == 0)
		{
			j++;
		}
		else if((com_c(av[i],del) == 1) && (com_c(av[i - 1],del) == 0))
		{
			arr_palabs[palabras] = malloc((j + 1) * sizeof(char));
			k = 0;
			for(i = i - j; k < j ; i++, k++)
			{
				arr_palabs[palabras][k] = av[i];
			}
			arr_palabs[palabras][j] = '\0';
			palabras++;
		}
		else
		{
			j = 0;
		}
	}
	arr_palabs[palabras] = malloc((j + 1) * sizeof(char));
	k = 0;
	for(i = i - j; k < j ; i++, k++)
	{
		arr_palabs[palabras][k] = av[i];
	}
	arr_palabs[palabras][j] = '\0';
	for (i = 0; arr_palabs[i] != 00; i++)
	            printf("palabras: %s\n", arr_palabs[i]);
//	return(arr_palabs);
	return(0);
}
