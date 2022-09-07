#include "shell.h"

/**
 * c_exit - frees user's typed command and linked list be4 exiting
 * @s: string or user's command
 * @env: input, linked list of environmentat variables
 */
void c_exit(char **s, list_t *env)
{
	free_ptr_ptr(s);
	free_linked_list(env);
	_exit(0);
}
/**
 * _execve - executes command user
 * @str: user typed command
 * @n: nth number user command used in error message
 * @env: env variables
 *
 * Return: 0
 */
int _execve(char **str, list_t *env, int n)
{
	char *hold;
	int status = 0, s = 0;
	pid_t pid;

	/* checking if the command is absolute path */
	if (access(str[0], F_OK) == 0)
	{
		hold = str[0];
		s = 1;
	}
	else
		hold = _which(str[0], env);
	if (access(hold, X_OK) != 0)
	{
		_notfound(str[0], n, env);
		free_ptr_ptr(str);
		return (127);
	}
	else
	{
		pid = fork();
		if (pid == 0) /* if child process, execute */
		{
			if (execve(hold, str, NULL) == -1)
			{
				_notfound(str[0], n, env); /* error msg */
				c_exit(str, env);
			}
		}
		else /* if parent, wait for child, free all */
		{
			wait(&status);
			free_ptr_ptr(str);
			if (s == 0)
				free(hold);
		}
	}
	return (0);
}
