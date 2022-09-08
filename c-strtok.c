#include "shell.h"

/**
 * cust_size - returns customised number of delim
 * @str: command into shell
 * @delim: delimiter i.e space" "
 *
 * Return: number of tokens.
 */
int cust_size(char *str, char delim)
{
	int i = 0, num_delim = 0;

	while (str[i] != '\0')
	{
		if (str[i] == delim)
		{
			num_delim++;
		}
		i++;
	}
	return (num_delim);
}
/**
 * c_strtok - tokenises a string,
 * the continuos delimiter with an empty string i.e
 * path --> ":/bin::/bin/user"
 * @str: command a user typed inputs into the shell
 * @delim: delimiter
 *
 * Return: array of token i.e. {"\0","/bin", "\0", "/bin/user"}
 */
char **c_strtok(char *str, char *delim)
{

	int buffersize = 0, p = 0, str_in = 0, i = 0, len = 0, str_end = 0;
	char delim_char, **tokens = NULL;

	/* setting the  variable to be delimeter character (" ") */
	delim_char = delim[0];
	/* malloc number of ptrs to store array of tokens, and NULL ptr */
	buffersize = cust_size(str, delim_char);
	tokens = malloc(sizeof(char *) * (buffersize + 2));
	if (tokens == NULL)
		return (NULL);

	/* iterate through a string from index 0 to ending index 'nth' */
	while (str[str_end] != '\0')
		str_end++;
	while (str_in < str_end)
	{
		/* malloc lengths for each token ptr in array */
		len = toks_strlen(str, str_in, delim_char);
		tokens[p] = malloc(sizeof(char) * (len + 1));
		if (tokens[p] == NULL)
			return (NULL);
		i = 0;
		while ((str[str_in] != delim_char) &&
				(str[str_in] != '\0'))
		{
			tokens[p][i] = str[str_in];
			i++;
			str_in++;
		}
		tokens[p][i] = '\0'; /* null terminate at end*/
		p++;
		str_in++;
	}
	tokens[p] = NULL; /* set last array ptr to NULL */
	return (tokens);
}
