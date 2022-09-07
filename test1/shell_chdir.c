#include "shell.h"

/**
 * cd_strcat - concatenate 2 strings ignoring first char i.e "~" in chdir(cd)
 * @dest: destinition, string to be appended
 * @src: source, to append a sting
 *
 * Return: concatenated string
 */
char *cd_strcat(char *dest, char *src)
{
	int len = 0, len2 = 0;
	int total_len = 0; /* total length */
	int j = 0;

	/* finding the total length for both strings to _realloc them */
	while (dest[len] != '\0')
	{
		len++;
		total_len++;
	}
	while (src[len2] != '\0')
	{
		len2++;
		total_len++;
	}

	/* _realloc because dest was malloced outside of function */
	dest = _realloc(dest, len, sizeof(char) * total_len + 1);

	j = 1; /* ignore the first character */
	while (src[j] != '\0')
	{
		dest[len] = src[j];
		len++;
		j++;
	}
	dest[len] = '\0';

	return (dest);
}
/**
 * cust_set_env - customises to set environmental var by cat string
 * 1st before settings
 * @env: linked list variables
 * @dir: directory path e.g /root/0x02_emacs
 * @name: variable name e.g oldpwd
 *
 * Return: 0
 */
int cust_set_env(list_t **env, char *name, char *dir)
{
	int index = 0, j = 0;
	char *cat;
	list_t *holder;

	cat = _strdup(name); /* create new concatenated string */
	cat = _strcat(cat, "=");
	cat = _strcat(cat, dir);
	index = find_env(*env, name); /* get idx to env var in linked list */

	/* traverse to index */
	holder = *env;
	while (j < index)
	{
		holder = holder->next;
		j++;
	}
	free(holder->var); /* free node data */
	holder->var = _strdup(cat);/* reassigning data to the node */
	free(cat); /* free cat pointer */
	return (0);
}
/**
 * cd_only - cd to home.
 * @env: linked list to update the paths
 * @cur: current working directory
 *
 * Return: void
 */
void cd_only(list_t *env, char *cur)
{
	char *home = NULL;

	home = get_env("HOME", env);
	cust_set_env(&env, "OLDPWD", cur); /* update environmental OLDPWD */
	free(cur);
	if (access(home, F_OK) == 0) /* if exist, go to home directory */
		chdir(home);
	cur = NULL;
	cur = getcwd(cur, 0);
	cust_set_env(&env, "PWD", cur); /* update environmental PWD */
	free(cur);
	free(home);
}
/**
 * cd_exec -  execute the cd command typed into the shell
 * @env: env linked list to keep the paths updated (PATH, OLDPWD)
 * @dir: directory path to cd
 * @cur: current working directory
 * @num: line number to write and output errors
 * @str: string of 1st argument to write and output error
 *
 * Return: 0
 */
int cd_exec(list_t *env, char *cur, char *dir, char *str, int num)
{
	int i = 0;

	if (access(dir, F_OK) == 0)
	{
		cust_set_env(&env, "OLDPWD", cur); /* update env OLDPWD */
		free(cur);
		chdir(dir);
		cur = NULL;
		cur = getcwd(cur, 0); /* get current working dir */
		cust_set_env(&env, "PWD", cur); /* update env PWD */
		free(cur);
	}
	else
	{
		can_not_cd_to(str, num, env);
		free(cur);
		i = 2;
	}
	return (i);
}
/**
 * _cd - change directory to new or previous
 * @str: command
 * @env: env linked list to retrieve home path, oldpwd path.
 * @num: command used at error message
 *
 * Return: 0 on success , if fails 2
 */
int _cd(char **str, list_t *env, int num)
{
	char *cur = NULL, *dir = NULL;
	int exit_stat = 0;

	cur = getcwd(cur, 0); /* store current working directory into cur */
	if (str[1] != NULL)
	{
		if (str[1][0] == '~') /* Usage: cd ~ */
		{
			dir = get_env("HOME", env);
			dir = cd_strcat(dir, str[1]);
		}
		else if (str[1][0] == '-') /* Usage: cd - */
		{
			if (str[1][1] == '\0')
				dir = get_env("OLDPWD", env);
		}
		else /* Usage: cd directory-1 */
		{
			if (str[1][0] != '/')
			{
				dir = getcwd(dir, 0);
				dir = _strcat(dir, "/");
				dir = _strcat(dir, str[1]);
			}
			else
				dir = _strdup(str[1]);
		}
		exit_stat = cd_exec(env, cur, dir, str[1], num);
		free(dir);
	}
	else /* Usage: cd */
		cd_only(env, cur);
	free_ptr_ptr(str); /* frees user input */
	return (exit_stat);
}
