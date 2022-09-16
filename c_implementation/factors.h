#ifndef FACTORS_H
#define FACTORS_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

/**
 * struct prime_s - linked list representation of a large number
 * @n: prime number
 * @next: points to the next element of the stack (or queue)
 *
 * Description: linked list node structure to hold prime numbers
 */
typedef struct prime_s
{
	unsigned long n;
	unsigned int idx;
	struct prime_s *next;
} prime_t;

/* LIST OPERATIONS */
prime_t *add_node(prime_t **tail, const unsigned long n);
void free_list(prime_t *head);

/* HELPERS */
int is_empty(char *buf, ssize_t wc);
int is_number(char *str);
char *division(char *denu,unsigned long nume, unsigned long *remainder);

#endif /* FACTORS_H */
