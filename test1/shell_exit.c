#include "shell.h"

/**
 * conv_atoi - atoi converts string into int
 * @str: string to be converted
 *
 * Return: number on success, -1 on fail
 */
unsigned int conv_atoi(char *str)
{
	int i = 0;
	unsigned int num = 0;

	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9') 
			num = num * 10 + (str[i] - '0');
		if (str[i] > '9' || str[i] < '0') 
			return (-1);
		i++;
	}
	return (num);
}
/**
 * _exit_ - exits main program with a value and after frees user input.
 * @*env: sets free environmental variables at error.
 * @str: command into shell "i.e. exit 98"
 * @num: nth user command line input to print in error message at error state
 * @command: the command to free
 *
 * Return: 0 on success , 2 on fail
 */
int _exit_(char **str, list_t *env, int num, char **cmd)
{
	int exit_value = 0;

	if (str[1] != NULL)
		exit_value = conv_atoi(str[1]);

	if (exit_value == -1)
	{
		illegal_num(str[1], num, env);
		free_ptr_ptr(str);
		return (2);
	}
	free_ptr_ptr(str);
	free_linked_list(env);
	if (cmd != NULL)
		free_ptr_ptr(cmd);
	exit(exit_value);
}
