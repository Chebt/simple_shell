#include "shell.h"

/**
 *  c_strdup - custom string duplication; excludes beginning bytes
 *  @str: string to duplicate (e.g. environmental variable PATH=/bin:/bin/ls)
 *  @num: number of bytes to exclude
 *  Return: string (e.g. /bin:/bin/ls)
 */
char *c_strdup(char *str, int num)
{
	char *dup_str;
	int i, len = 0;

	if (str == NULL)
		return (NULL);

	/* calculate len + null terminator to malloc */
	while (*(str + len))
		len++;
	len++;

	/* allocate memory but exclude environmental variable title (PATH) */
	dup_str = malloc(sizeof(char) * (len - num));
	if (dup_str == NULL)
		return (NULL);

	i = 0;
	while (i < (len - num))
	{
		*(dup_str + i) = *(str + num + i);
		i++;
	}
	return (dup_str);
}

/**
 *  get_env - finds and returns a copy of the requested environmental variable
 *  @str: string to store it in
 *  @env: entire set of environmental variables
 *
 * Return: copy of requested environmental variable
 */
char *get_env(char *str, list_t *env)
{
	int i = 0, num = 0;

	while (env != NULL)
	{
		i = 0;
		while ((env->var)[i] == str[i]) /* find desired env variable */
			i++;
		if (str[i] == '\0' && (env->var)[i] == '=')
			break;
		env = env->next;
	}

	while (str[num] != '\0') /* find how many bytes in env variable title */
		num++;
	num++; /*counts one more for = sign*/
	return (c_strdup(env->var, num)); /* make a copy of variable w/o title */
}
