/*
** EPITECH PROJECT, 2021
** include
** File description:
** pushswap
*/

#ifndef include_ismalloc
    #define include_ismalloc

    #include "stdlib.h"
    #include "my.h"
    #include <stdio.h>

typedef struct ismalist {
    void *adress;
    struct ismalist *next;
} ismalist_t;

typedef struct alex {
    char *str;
    int *alexint;
} alex_t;

void *ismalloc(size_t size);

static void frisma(void) __attribute__((destructor));

#endif /* include_ismalloc */
