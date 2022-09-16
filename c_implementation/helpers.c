#include "factors.h"

/**
 * is_empty - checks if a line is empty
 * @wc: word count
 *
 * Return: 0 or 1
 */
int is_empty(char *buf, ssize_t wc)
{
	size_t i = 0;

	if (wc == 0)
		return (1);
	
	while (buf[i] != '\0')
	{
		if (buf[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

/**
 * is_number - checks if a given string is a number
 * @str: string
 *
 * Return: 0 or 1
 */
int is_number(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		if (i == 0 && str[i] == '-')
		{
			i++;
			continue;
		}
		if (str[i] < 48 || str[i] > 57)
			return (0);
		i++;
	}
	return (1);
}
