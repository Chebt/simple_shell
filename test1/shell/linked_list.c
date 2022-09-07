#include "shell.h"

/**
 * print_list - _print linked list
 * @list: linked list
 * Return: size of linked list
*/
ssize_t print_list(list_t *list)
{
	list_t *c_list = list;
	int count = 0;
	int count1 = 0;

	if (list == NULL)
		return (0);
	while (c_list != NULL)
	{
		if (c_list->var == NULL)
		{
			write(STDOUT_FILENO, "(nil)", 5);
			write(STDOUT_FILENO, "\n", 1);
		}
		else
		{
			count1 = 0;
			while ((c_list->var)[count1] != '\0')
				count1++;
			write(STDOUT_FILENO, c_list->var, count1);
			write(STDOUT_FILENO, "\n", 1);
		}
		c_list = c_list->next;
		count++;
	}
	return (count);
}

/**
 *  add_node_t_end - add node to end of linked list
 *  @head: pointer to head of linked list
 *  @str: data to new node
 *  Return: pointer to new linked list
 */
list_t *add_node_t_end(list_t **head, char *str)
{
	list_t *new;
	list_t *holder;

	if (head == NULL || str == NULL)
		return (NULL); /* check if address of head is null */
	new = malloc(sizeof(list_t));
	if (new == NULL)
		return (NULL);

	new->var = _strdup(str);
	new->next = NULL;

	holder = *head;
	if (holder != NULL)
	{
		while (holder->next != NULL)
		{
			holder = holder->next;
		}
		holder->next = new;
	}
	else
	{
		*head = new;
	}
	return (*head);
}

/**
 *  delete_nodeint_at_index - removing node at index
 *  @head: input head address
 *  @index: input index of the node to be deleteed
 *  Return: 1 if success, -1 if fail
 */
int delete_nodeint_at_index(list_t **head, unsigned int index)
{
	list_t *p_head;
	list_t *holder;
	unsigned int count = 0;

	if (*head == NULL)
		return (-1);
	if (index == 0)
	{
		holder = (*head)->next;
		free((*head)->var);
		free(*head);
		*head = holder;
		return (1);
	}
	count = 1;
	p_head = *head;
	while (count < index)
	{
		if (p_head == NULL)
			return (-1);
		p_head = p_head->next;
		count++;
	}
	holder = p_head->next;
	p_head->next = holder->next;
	free(holder->var);
	free(holder);
	return (1);
}

/**
 *  free_linked_list - frees linked list
 *  @head: linked list
 */
void free_linked_list(list_t *head)
{
	list_t *holder;

	while (head != NULL)
	{
		holder = head;
		head = head->next;
		free(holder->var);
		free(holder);
	}

}
