#include "factors.h"

/**
 * get_factors - compute factors of a given integer
 * @num: integer
 *
 * Return: 0 on sucess and -1 on failure
 *
 * Description: every whole number larger than 1 can be
 * uniquely expressed as the product of its prime numbers
 */
int get_factors(char *num, prime_t *head, prime_t *tail)
{
	prime_t *primenumber, *temp;
	char *quo, *denom;
	unsigned long remainder = 0, i;
	int flag = 1;

	denom = strdup(num);
	primenumber = head;
	while (flag)
	{
		quo = division(denom, primenumber->n, &remainder);
		if (remainder == 0)
		{
			printf("%s=%s*%lu\n", denom, quo, primenumber->n);
			return (0);
		}
		if (primenumber->next == NULL)
		{
			i = primenumber->n + 2;
			while (i < (primenumber->n + 100))
			{
				temp = head;;
				while (temp->next)
				{
					printf("%lu -- %lu = %lu\n", i, temp->n, i % temp->n);
					if (i % temp->n == 0)
					{
						break;
					}
					temp = temp->next;
				}
				if (i % temp->n != 0)
				{
					add_node(&tail, i);
					break;
				}
				i += 2;
			}
		}
		primenumber = primenumber->next;
	}
	return (-1);
}

/**
 * main - Entry point
 * @ac: argument count
 * @av: arguments
 *
 * Return: EXIT_SUCCESS or EXIT_FALIURE
 */
int main(int ac, char *av[])
{
	FILE *stream;
	char *buf = NULL;
	size_t len = 0;
	ssize_t wc;
	prime_t *head = NULL, *tail = NULL;
	
	head = add_node(&tail, 2);
	add_node(&tail, 3);
	add_node(&tail, 5);
	add_node(&tail, 7);
	if (ac != 2)
	{
		fprintf(stderr, "USAGE: %s <file>\n", av[0]);
		exit(EXIT_FAILURE);
	}

	stream = fopen(av[1], "r");
	if (stream == NULL)
	{
		fprintf(stderr, "Error: can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}

	while ((wc = getline(&buf, &len, stream)) != -1)
	{
		buf[strcspn(buf, "\n")] = '\0';
		if ((get_factors(buf, head, tail)) == -1)
			exit(EXIT_FAILURE);
		/* REMOVE PRINT */
	       /*	
		printf("%s %% %lu\n", division(buf, head->n, &remainder), remainder);
		*/
	}
	free(buf);
	fclose(stream);
	exit(EXIT_SUCCESS);
}
