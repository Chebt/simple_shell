#include "shell.h"

/**
 *  _realloc - allocate memory and set all values to 0
 *  @p: pointer to the memory previously allocated (malloc(old_size))
 *  @old_size: size previously allocated
 *  @new_size: new size to reallocate
 *
 * Return: pointer to reallocated memory
*/
void *_realloc(void *p, unsigned int old_size, unsigned int new_size)
{
	void *res;
	unsigned int i;

	if (new_size == 0 && p != NULL) /* free memory if reallocate 0 */
	{
		free(p);
		return (NULL);
	}

	if (new_size == old_size) /* return pointer if reallocating same old size */
		return (p);
	/* memory allocate for new size if pointer is originally null */
	if (p == NULL)
	{
		res = malloc(new_size);
		if (res == NULL)
			return (NULL);
		else
			return (res);
	}

	res = malloc(new_size); /* memory allocate and check for error */
	if (res == NULL)
		return (NULL);

	/* here, fill values up till minimum of old or new size */
	for (i = 0; i < old_size && i < new_size; i++)
		*((char *)res + i) = *((char *)p + i);
	free(p); /* free the old pointer */

	return (res);
}
