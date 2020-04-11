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
char** _strtok(char *a)
{
	if(!a)
		return(NULL);
	int j = 0, i = 0, palabras = 1, k = 0;
	char **arr_palabs;
	char *d = DELIMITER;
	for (i = 0; a[i]; i++)
	{
		if((com_c(a[i],d) == 1) && (com_c(a[i - 1],d) == 0) && a[i + 1])
		{
			palabras++;
		}
	}
	arr_palabs = malloc((palabras + 1) * sizeof(char *));
	arr_palabs[palabras] = NULL;
	palabras = 0;
	for (i = 0; a[i]; i++)
	{
		if ((com_c(a[i],d)) == 0)
		{
			j++;
		}
		else if((com_c(a[i],d) == 1) && (com_c(a[i - 1],d) == 0))
		{
			arr_palabs[palabras] = malloc((j + 1) * sizeof(char));
			k = 0;
			for(i = i - j; k < j ; i++, k++)
			{
				arr_palabs[palabras][k] = a[i];
			}
			arr_palabs[palabras][j] = '\0';
			palabras++;
			j = 0;
		}
	}
	arr_palabs[palabras] = malloc((j + 1) * sizeof(char));
	k = 0;
	for(i = i - j; k < j ; i++, k++)
	{
		arr_palabs[palabras][k] = a[i];
	}
	arr_palabs[palabras][j] = '\0';
	for (i = 0; arr_palabs[i] != 00; i++)
	            printf("palabras: %s\n", arr_palabs[i]);
	return(arr_palabs);
}
