#ifndef FACTORS_H
#define FACTORS_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

/**
 * struct number_s - linked list representation of a large number
 * @n: string
 * @next: points to the next element of the stack (or queue)
 *
 * Description: linked list node structure to hold chunks 
 * from large digits
 */
typedef struct number_s
{
	char *n;
	struct number_s *next;
} number_t;

/* HELPERS */
int is_empty(char *buf, ssize_t wc);
int is_number(char *str);

#endif /* FACTORS_H */
