#include "shell.h"

/**
 *  get_line - stores into malloced buffer the user's command into shell
 *  @str: buffer
 *  Return: number of characters read
 */
size_t get_line(char **str)
{
	ssize_t i = 0, size = 0, t = 0, t1 = 0, n = 0;
	char buffer[1024];

	while (t1 == 0 && (i = read(STDIN_FILENO, buffer, 1024 - 1)))
	{
		if (i == -1) /* check if read failed */
			return (-1);

		buffer[i] = '\0'; /* terminate buffer */

		n = 0; /* loop if new line is found in the stdin read */
		while (buffer[n] != '\0')
		{
			if (buffer[n] == '\n')
				t1 = 1;
			n++;
		}
		if (t == 0) /* malloc the first time */
		{
			i++;
			*str = malloc(sizeof(char) * i);
			*str = _strcpy(*str, buffer);/* copywhat's read to buffer into */
			size = i; /* getline's buffer */
			t = 1;
		}
		else /* _realloc via _string concatenate with each loop */
		{
			size += i;
			*str = _strcat(*str, buffer);
		}
	}
	return (size);
}
