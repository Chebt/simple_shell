#include "shell.h"

/**
 *  _which - fleshes out command by appending it to a matching PATH directory
 *  @str: first command user typed into shell i.e. "ls" if user typed "ls -l"
 *  @env: environmental variable
 *  Return: a copy of fleshed out command i.e. "/bin/ls" if originally "ls"
 */
char *_which(char *str, list_t *env)
{
	char *path, *cat = NULL, **tokens;
	int i = 0;

	path = get_env("PATH", env); /* get the PATHA dir's and store them to pth */
	tokens = c_strtok(path, ":"); /* tokenize pth at ":" */
	free(path); /* free the original string */

	/* append "/command" to each token to see it's good and legal */
	i = 0;
	while (tokens[i] != NULL)
	{
		if (tokens[i][0] == '\0')
			cat = getcwd(cat, 0);
		else
			cat = _strdup(tokens[i]);
		cat = _strcat(cat, "/");
		cat = _strcat(cat, str);
		/* on succes mode is F_OK and the file exists */
		if (access(cat, F_OK) == 0)
		{
			/* free tokens before returning legal fleshed path */
			free_ptr_ptr(tokens);
			return (cat);
		}
		free(cat); /* free concatenated string if command is never found */
		i++;
	}
	free_ptr_ptr(tokens);
	return (str); /* return string, if not found; won't pass execve */
}
