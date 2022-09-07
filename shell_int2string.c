#include "shell.h"

/**
 *  num_len - counts number of 0s in a tens power number
 *  @num: number
 *
 *  Return: returns count of digits
 */
int num_len(int num)
{
	int count = 0;
	int n = num;

	while (n > 9 || n < -9)
	{
		n /= 10;
		count++;
	}
	return (count);
}
/**
 *  int_to_string - turns an int into a string
 *  @num: integer
 *
 *  Return: returns the int as a string. returns NULL if failed
 */
char *int_to_string(int num)
{
	int digits, tens, i = 0, t = 0, x;
	char *res;

	digits = num;
	tens = 1;

	if (num < 0)
		t = 1;
	res = malloc(sizeof(char) * (num_len(digits) + 2 + t));
	if (res == NULL)
		return (NULL);
	if (num < 0)
	{
		res[i] = '-';
		i++;
	}
	for (x = 0; digits > 9 || digits < -9; x++)
	{
		digits /= 10;
		tens *= 10;
	}
	for (digits = num; x >= 0; x--)
	{
		if (digits < 0)
		{
			res[i] = (digits / tens) * -1 + '0';
			i++;
		}
		else
		{
			res[i] = (digits / tens) + '0';
			i++;
		}
		digits %= tens;
		tens /= 10;
	}
	res[i] = '\0';
	return (res);
}
