#include "shell.h"
/**
 * _strcmp - compares two strings
 * @s1: destination
 * @s2: source
 * Return: 0 if succes.
 */
int _strcmp(char *s1, char *s2)
{
	int long_of_dest;

	for (long_of_dest = 0; s1[long_of_dest] != '\0'; long_of_dest++)
	{
		if (s1[long_of_dest] != s2[long_of_dest])
		{
			return (s1[long_of_dest] - s2[long_of_dest]);
		}
	}
	return (0);
}
