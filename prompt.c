#include "shell.h"

/**
<<<<<<< HEAD
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
		_set_env(&env, tok);
		i = 1;
	}
	/* if user inputs "unsetenv", remove linked list node */
	else if (_strcmp(tok[0], "unsetenv") == 0)
	{
		_unset_env(&env, tok);
=======
 * ctrl_c - ignore Ctrl-C input and prints prompt again
 * @n: takes in int from signal
 */
void ctrl_c(int n)
{
	(void)n;
	write(STDOUT_FILENO, "\n$ ", 3);
}

/**
 * built_in - handles builtins (exit, env, cd)
 * @token: user's typed command
 * @env: environmental variable
 * @num: take in nth user command typed to write error message
 * @command: bring in command to free
 * Return: 1 if acted on builtin, 0 if not
 */
int built_in(char **token, list_t *env, int num, char **command)
{
	int i = 0;

	/* if user types "exit", free cmd tokens, and exit */
	if (_strcmp(token[0], "exit") == 0)
	{
		i = __exit(token, env, num, command);
	}
	/* if user types "env", print, free cmd tokens, and reprompt */
	else if (_strcmp(token[0], "env") == 0)
	{
		_env(token, env);
		i = 1;
	}
	/* if user types "cd" , it will change directory */
	else if (_strcmp(token[0], "cd") == 0)
	{
		i = _cd(token, env, num);
	}
	/* if user types "setenv", create or modify linked list node */
	else if (_strcmp(token[0], "setenv") == 0)
	{
		_setenv(&env, token);
		i = 1;
	}
	/* if user types "setenv", remove linked list node */
	else if (_strcmp(token[0], "unsetenv") == 0)
	{
		_unsetenv(&env, token);
>>>>>>> jose1
		i = 1;
	}
	return (i);
}

/**
<<<<<<< HEAD
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
=======
 * ignore_space - return string without spaces in front
 * @str: string
 * Return: new string
 */
char *ignore_space(char *str)
{
	while (*str == ' ')
		str++;
	return (str);
}

/**
 * ctrl_D - exits program if Ctrl-D was pressed
 * @i: characters read via get_line
 * @command: user's typed in command
 * @env: environmental variable linked list
 */
void ctrl_D(int i, char *command, list_t *env)
{
	if (i == 0) /* handles Ctrl+D */
	{
		free(command); /* exit with newline if in shell */
>>>>>>> jose1
		free_linked_list(env);
		if (isatty(STDIN_FILENO))/* ctrl+d prints newline */
			write(STDOUT_FILENO, "\n", 1);
		exit(0);
	}
}

/**
<<<<<<< HEAD
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
		tok = _strtok(cmd, " "); /*token user cmd*/
		if (n_cmd != NULL)
			free(n_cmd);
		exit_status = _built_in(tok, _env, cmd_line_no, NULL);
		if (exit_status)
			continue;
		exit_status = _execve(tok, _env, cmd_line_no);
	} while (1); /* keep on repeating till user exits shell */
	return (exit_status);
=======
 * prompt - repeatedly prompts user and executes user's cmds if applicable
 * @en: envrionmental variables
 * Return: 0 on success
 */
int prompt(char **en)
{
	list_t *env;
	size_t i = 0, n = 0;
	int command_line_no = 0, exit_stat = 0;
	char *command, *n_command, **token;

	env = env_linked_list(en);
	do {
		command_line_no++;
		if (isatty(STDIN_FILENO)) /* reprompt if in interactive shell */
			write(STDOUT_FILENO, "$ ", 2);
		else
			non_interactive(env);
		signal(SIGINT, ctrl_c); /* makes ctrl+c not work */
		command = NULL; i = 0; /* reset vars each time loop runs */
		i = get_line(&command); /* read user's cmd in stdin */
		ctrl_D(i, command, env); /* exits shell if ctrl-D */
		n_command = command;
		command = ignore_space(command);
		n = 0;
		while (command[n] != '\n') /* replace get_line's \n with \0 */
			n++;
		command[n] = '\0';
		if (command[0] == '\0') /* reprompt if user hits enter only */
		{
			free(n_command); continue;
		}
		token = NULL; token = _str_tok(command, " "); /*token user cmd*/
		if (n_command != NULL)
			free(n_command);
		exit_stat = built_in(token, env, command_line_no, NULL);
		if (exit_stat)
			continue;
		exit_stat = _execve(token, env, command_line_no);
	} while (1); /* keep on repeating till user exits shell */
	return (exit_stat);
>>>>>>> jose1
}
