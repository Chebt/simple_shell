#include "shell.h"

/**
 *  _notfound - write error ("sh: 1: lss: not found")
 *  @s: user's typed command
 *  @c_n: nth user's typed command
 *  @env: bring in environmental variables linked list to write shell name
 */
void _notfound(char *s, int c_n, list_t *env)
{
	int count = 0;
	char *c_shell, *num;

	c_shell = get_env("_", env); /* get shell name to write */
	while (c_shell[count] != '\0')
		count++;
	write(STDOUT_FILENO, c_shell, count);
	free(c_shell);
	write(STDOUT_FILENO, ": ", 2);
	num = int_to_string(c_n); /* convert cmd line num to string to write */
	count = 0;
	while (num[count] != '\0')
		count++;
	write(STDOUT_FILENO, num, count);
	free(num);
	write(STDOUT_FILENO, ": ", 2);
	count = 0;
	while (s[count] != '\0')
		count++;
	write(STDOUT_FILENO, s, count);
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, "not found\n", 10);
}

/**
 *  can_not_cd_to - write error ("sh: 2: cd: can't cd to xyz")
 *  @s: user's typed argument after the cmd cd
 *  @c_n: nth user's typed command
 *  @env: bring in environmental variables linked list to write shell name
 */
void can_not_cd_to(char *s, int c_n, list_t *env)
{
	int count = 0;
	char *c_shell, *num;

	c_shell = get_env("_", env);
	while (c_shell[count] != '\0')
		count++;
	write(STDOUT_FILENO, c_shell, count);
	free(c_shell);
	write(STDOUT_FILENO, ": ", 2);
	num = int_to_string(c_n);
	count = 0;
	while (num[count] != '\0')
		count++;
	write(STDOUT_FILENO, num, count);
	free(num);
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, "cd: can't cd to ", 16);
	count = 0;
	while (s[count] != '\0')
		count++;
	write(STDOUT_FILENO, s, count);
	write(STDOUT_FILENO, "\n", 1);
}

/**
 *  forbid_num - write error ("sh: 3: exit: Illegal number abc (or -1)")
 *  @s: user's typed argument after the cmd exit
 *  @c_n: nth user's typed command
 *  @env: bring in environmental variables linked list to write shell name
 */
void forbid_num(char *s, int c_n, list_t *env)
{
	int count = 0;
	char *c_shell = NULL, *num = NULL;

	c_shell = get_env("_", env);
	while (c_shell[count] != '\0')
		count++;
	write(STDOUT_FILENO, c_shell, count);
	free(c_shell);
	write(STDOUT_FILENO, ": ", 2);
	num = int_to_string(c_n);
	count = 0;
	while (num[count] != '\0')
		count++;
	write(STDOUT_FILENO, num, count);
	free(num);
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, "exit: Illegal number: ", 22);
	count = 0;
	while (s[count] != '\0')
		count++;
	write(STDOUT_FILENO, s, count);
	write(STDOUT_FILENO, "\n", 1);
}
