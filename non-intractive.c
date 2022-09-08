#include "shell.h"

/**
 *  c_ignore - custom ignores spaces and newlines
 *  (e.g. echo "ls\n ls" | ./hsh)
 *  @str: envrionmental variables
 *
 *  Return: new string
 */
char *c_ignore(char *str)
{
	while (*str == ' ' || *str == '\n')
		str++;
	return (str);
}

/**
 *  non_interactive - handles when user pipes commands into shell via pipeline
 *  (i.e. echo "ls/nls -al/n" | ./hsh)
 *  @env: envrionmental variables
 */
void non_interactive(list_t *env)
{
	size_t i = 0, n = 0;
	int cmd_line_no = 0, exit_status = 0;
	char *cmd = NULL, *n_cmd = NULL, **n_line, **tok;

	i = get_line(&cmd);
	if (i == 0)
	{
		free(cmd);
		exit(0);
	}
	n_cmd = cmd;
	cmd = c_ignore(cmd);
	n_line = _strtok(cmd, "\n"); /* tokenize each command string */
	if (n_cmd != NULL)
		free(n_cmd);
	n = 0;
	while (n_line[n] != NULL)
	{
		cmd_line_no++;
		tok = NULL; /* tokenize each command in array of commands */
		tok = _strtok(n_line[n], " ");
		exit_status = _built_in(tok, env, cmd_line_no, n_line);
		if (exit_status)
		{
			n++;
			continue;
		}
		exit_status = _execve(tok, env, cmd_line_no);
		n++;
	}
	free_ptr_ptr(n_line);
	free_linked_list(env);
	exit(exit_status);
}
