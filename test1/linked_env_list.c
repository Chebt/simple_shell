#include "shell.h"

/**
 * env_linked_list - creates a linked list from env variables
 * @env: env variables
 *
 * Return: linked list
 */
list_t *env_linked_list(char **env)
{
	list_t *head;
	int i;

	head = NULL;
	for (i = 0; env[i] != NULL; i++)
	{
		add_end_node(&head, env[i]);
	}
	return (head);
}
/**
 * p_env - prints environmental variables
 * @env: environmental variables
 * @s: user's command into shell i.e cd
 *
 * Return: 0
 */
int p_env(char **s, list_t *env)
{
	free_ptr_ptr(s); /* frees user input */
	print_list(env); /* prints env */
	return (0);
}
