#include "shell.h"

/**
 *   _strcmp - compare two strings
 *   @str1: string 1
 *   @str2: string 2
 *
 *  Return: int that tells num spaces in between, 0 if exactly the same string
 */

int _strcmp(char *str1, char *str2)
{
	int j = 0;

	while (*(str1 + j) == *(str2 + j) && *(str1 + j))
		j++;

	if (*(str2 + j))
		return (*(str1 + j) - *(str2 + j));
	else
		return (0);
}
