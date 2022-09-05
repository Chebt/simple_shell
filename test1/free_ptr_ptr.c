#include "shell.h"

/**
   free_ptr_ptr - free malloced arrays
 * @str: array of strings
 */
void free_ptr_ptr(char **str)
{
	int i = 0;

	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	free(str);
}
