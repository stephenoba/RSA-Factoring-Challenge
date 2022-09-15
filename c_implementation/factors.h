#ifndef FACTORS_H
#define FACTORS_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

/* HELPERS */
int is_empty(char *buf, ssize_t wc);
int is_number(char *str);

#endif /* FACTORS_H */
