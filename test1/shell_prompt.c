#include "shell.h"

/**
 *   ctrl_c - ignore Ctrl-C input and prints prompt again
 *   @number: takes in int from signal
 */
void ctrl_c(int number)
{
	(void)number;
	write(STDOUT_FILENO, "\n~$ ", 3);
}

/**
 *  _built_in - handles builtins (exit, env, cd)
 *  @tok: user's typed command
 *  @env: environmental variable
 *  @num: take in nth user command typed to write error message
 *  @cmd: bring in command to free
 *
 *  Return: 1 if acted on builtin, 0 if not
 */
int _built_in(char **tok, list_t *env, int num, char **cmd)
{
	int i = 0;

	/* if user inputs "exit", free cmd tokens, and exit */
	if (_strcmp(tok[0], "exit") == 0)
	{
		i = _exit_(tok, env, num, cmd);
	}
	/* if user inputs "env", print, free cmd tokens, and reprompt */
	else if (_strcmp(tok[0], "env") == 0)
	{
		p_env(tok, env);
		i = 1;
	}
	/* if user inputs "cd" , it will change directory */
	else if (_strcmp(tok[0], "cd") == 0)
	{
		i = _cd(tok, env, num);
	}
	/* if user inputs "setenv", create or modify linked list node */
	else if (_strcmp(tok[0], "setenv") == 0)
	{
		_setenv(&env, tok);
		i = 1;
	}
	/* if user inputs "unsetenv", remove linked list node */
	else if (_strcmp(tok[0], "unsetenv") == 0)
	{
		_unsetenv(&env, tok);
		i = 1;
	}
	return (i);
}

/**
 *  ignore_space - return string without spaces in front
 *  @s: string
 *
 *  Return: new string
 */
char *ignore_space(char *s)
{
	while (*s == ' ')
		s++;
	return (s);
}

/**
 *   ctrl_D - exits program when Ctrl-D is pressed
 *   @i: characters read via get_line
 *   @cmd: user's typed in command
 *   @env: environmental variable linked list
 */
void ctrl_D(int i, char *cmd, list_t *env)
{
	if (i == 0) /* handles Ctrl+D */
	{
		free(cmd); /* exit with newline if in shell */
		free_linked_list(env);
		if (isatty(STDIN_FILENO))/* ctrl+d prints newline */
			write(STDOUT_FILENO, "\n", 1);
		exit(0);
	}
}

/**
 *  prompt - repeatedly prompts user and executes user's cmds if applicable
 *  otherwise returns error.
 *  @env: envrionmental variables
 *  Return: 0 on success
 */
int prompt(char **env)
{
	list_t *_env;
	size_t i = 0, n = 0;
	int cmd_line_no = 0, exit_status = 0;
	char *cmd, *n_cmd, **tok;

	_env = env_linked_list(env);
	do {
		cmd_line_no++;
		if (isatty(STDIN_FILENO)) /* reprompt if in interactive shell */
			write(STDOUT_FILENO, "$ ", 2);
		else
			non_interactive(_env);
		signal(SIGINT, ctrl_c); /* makes ctrl+c not work */
		cmd = NULL;
		i = 0; /* reset vars each time loop runs */
		i = get_line(&cmd); /* read user's cmd in stdin */
		ctrl_D(i, cmd, _env); /* exits shell if ctrl-D */
		n_cmd = cmd;
		cmd = ignore_space(cmd);
		n = 0;
		while (cmd[n] != '\n') /* replace get_line's \n with \0 */
			n++;
		cmd[n] = '\0';
		if (cmd[0] == '\0') /* reprompt if user hits enter only */
		{
			free(n_cmd);
			continue;
		}
		tok = NULL;
		tok = _str_tok(cmd, " "); /*token user cmd*/
		if (n_cmd != NULL)
			free(n_cmd);
		exit_status = _built_in(tok, _env, cmd_line_no, NULL);
		if (exit_status)
			continue;
		exit_status = _execve(tok, _env, cmd_line_no);
	} while (1); /* keep on repeating till user exits shell */
	return (exit_status);
}
