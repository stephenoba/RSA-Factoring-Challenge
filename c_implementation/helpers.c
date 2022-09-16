#include "factors.h"

char *division(char *denu, unsigned long nume, unsigned long *remainder)
{
	static char quotient[100];
	int len_denom;
	char *denom;
	int i, k = 0, flag = 0;
	unsigned long temp = 1;

	denom = strdup(denu);
	len_denom = strlen(denom);
	for(i = 0; i <= len_denom; i++)
	{
		denom[i] = denom[i] - 48;
	}

	temp = denom[0];
	*remainder = denom[0];
	for(i = 1; i <= len_denom; i++)
	{
		if(nume <= temp)
		{
			quotient[k++] = temp / nume;
			temp = temp % nume;
			*remainder = temp;
			temp = temp * 10 + denom[i];
			flag=1;
		}
		else
		{
			*remainder = temp;
			temp = temp * 10 + denom[i];
			if(flag==1)
				quotient[k++] = 0;
		}
	}

	for(i = 0; i < k; i++){
		quotient[i] = quotient[i] + 48;
	}
	quotient[i]= '\0';
	free(denom);

	return (quotient);
}

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
