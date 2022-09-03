#include "shell.h"


list_t *env_linked_list(char **env)
{
	list_t *head;
	int i = 0;

	head = NULL;
	while (env[i] != NULL)
	{
		add_end_node(&head, env[i]);
		i++;
	}
	return (head);
}

int _env(char **str, list_t *env)
{
	free_double_ptr(str); /* frees user input */
	print_list(env); /* prints env */
	return (0);
}
