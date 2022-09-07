#include "shell.h"

/**
 *  toks_strlen - returns token's string length for mallocing
 *  @str: a token
 *  @p: index position in user's command typed into shell
 *  @delim: delimeter (e.g. " ");
 *  Return: length of token
 */
int toks_strlen(char *str, int p, char delim)
{
	int len = 0;

	while ((str[p] != delim) && (str[p] != '\0'))
	{
		p++;
		len++;
	}
	return (len);
}

/**
 *  toks_size - returns number of delim ignoring continuous delim
 *  @str: user's command typed into shell
 *  @delim: delimeter (e.g. " ");
 *
 *  Return: number of delims so that (num token = delims + 1)
 */
int toks_size(char *str, char delim)
{
	int i = 0, num_delim = 0;

	while (str[i] != '\0')
	{
		if ((str[i] == delim) && (str[i + 1] != delim))
		{
			/* handle continuous delims */
			num_delim++;
		}
		if ((str[i] == delim) && (str[i + 1] == '\0'))
		{
			/*handle continuous delims after full command */
			num_delim--;
		}
		i++;
	}
	return (num_delim);
}

/**
 * ignore_delim - returns a version of string without preceeding delims
 * @str: string
 * @delim: delimiter (e.g. " ")
 *
 * Return: new string (e.g. "    ls -l" --> "ls -l")
 */
char *ignore_delim(char *str, char delim)
{
	while (*str == delim)
		str++;
	return (str);
}

/**
 * _strtok - tokenizes a string and returns an array of tokens
 * @str: user's command typed into shell
 * @delim: delimeter (e.g. " ");
 *
 * Return: an array of tokens (e.g. {"ls", "-l", "/tmp"}
 */
char **_strtok(char *str, char *delim)
{
	int buff_size = 0, p = 0, str_index0 = 0, i = 0, len = 0, str_end = 0, t = 0;
	char **tokens = NULL, delim_char;

	delim_char = delim[0];
	/* creates new version of string ignoring all delims infront*/
	str = ignore_delim(str, delim_char);
	/* malloc ptrs to store array of tokens (buffsize + 1), and NULL ptr */
	buff_size = toks_size(str, delim_char);
	tokens = malloc(sizeof(char *) * (buff_size + 2));
	if (tokens == NULL)
		return (NULL);
	while (str[str_end] != '\0')	/* find string ending index */
		str_end++;
	while (str_index0 < str_end)
	{ /* malloc lengths for each token ptr in array */
		if (str[str_index0] != delim_char)
		{
			len = toks_strlen(str, str_index0, delim_char);
			tokens[p] = malloc(sizeof(char) * (len + 1));
			if (tokens[p] == NULL)
				return (NULL);
			i = 0;
			while ((str[str_index0] != delim_char) && (str[str_index0] != '\0'))
			{
				tokens[p][i] = str[str_index0];
				i++;
				str_index0++;
			}
			tokens[p][i] = '\0'; /* null terminate at end*/
			t++;
		}
		/* handle repeated delimeters; increment ptr after ("ls __-l")*/
		if (str_index0 < str_end && (str[str_index0 + 1] != delim_char
					&& str[str_index0 + 1] != '\0'))
			p++;
		str_index0++;
	}
	p++;
	tokens[p] = NULL; /* set last array ptr to NULL */
	return (tokens);
}
