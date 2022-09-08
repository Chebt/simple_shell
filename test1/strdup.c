#include "shell.h"

/**
 * _strdup - returns a pointer to a newly allocated space in memory,
 * which contains a copy of the string given as a parameter
 * @str: string to duplicate
 *
 * Return: pointer to duplicated string
 */
char *_strdup(char *str)
{
	char *dup_str;
	int i, len = 0;

	if (str == NULL) /* validate str input */
		return (NULL);

	while (*(str + len))
		len++;
	len++; /* add null terminator to length */

	dup_str = malloc(sizeof(char) * len); /* allocate memory */
	if (dup_str == NULL)
		return (NULL);

	i = 0;
	while (i < len)
	{
		*(dup_str + i) = *(str + i);
		i++;
	}

	return (dup_str);/* in allocated memory */
}
