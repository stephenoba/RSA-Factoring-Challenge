#include "factors.h"

int div(char *a, int b):
{
}

/**
 * get_factors - compute factors of a given integer
 * @num: integer
 *
 * Return: 0 on sucess and -1 on failure
 *
 * Description: every whole number larger than 1 can be
 * uniquely expressed as the product of its prime numbers
 */
int get_factors(const unsigned long long num)
{
	/* Array of prime numbers from 1 - 100 */
	unsigned long long prime_numbers[] = {
		2, 3, 5, 7, 11, 13, 17, 19,
		23, 29, 31, 37, 41, 43, 47,
		53, 59, 61, 67, 71, 73, 79,
		83, 89, 97, 101, 103, 107,
		109, 113, 127, 131, 137, 139,
		149, 151, 157, 163, 167, 173,
		179, 181, 191, 193, 197, 199,
		211, 223, 227, 229, 233, 239,
		241, 251, 257, 263, 269, 271,
		277, 281, 283, 293
	};
	int i;
	unsigned long long p;

	for (i = 0; i < 25; i++)
	{
		p = prime_numbers[i];
		if (num % p == 0)
		{
			printf("%lld=%lld*%lld\n", num, num/p, p);
			return (0);
		}
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
	unsigned long long num;

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
		num = atoi(buf);
		if ((get_factors(num)) == -1)
			exit(EXIT_FAILURE);
	}
	free(buf);
	fclose(stream);
	exit(EXIT_SUCCESS);
}