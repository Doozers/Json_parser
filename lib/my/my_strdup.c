/*
** EPITECH PROJECT, 2022
** minishell1
** File description:
** No file there , just an epitech header example
*/

#include "my.h"
#include "../../include/ismalloc.h"
#include <stdlib.h>

char *my_strdup(char const *src)
{
    int src_length = my_strlen(src);
    char *copy = ismalloc((src_length + 1) * sizeof(char));

    for (int index = 0; *(src + index) != '\0'; index++)
        *(copy + index) = *(src + index);
    copy[src_length] = '\0';
    return copy;
}
