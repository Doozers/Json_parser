/*
** EPITECH PROJECT, 2021
** my
** File description:
** my_showarray
*/

#include "my.h"
#include <stdio.h>

void my_showarray(char **array)
{
    for (int i = 0; array[i] != NULL; i++) {
        my_putstr(array[i]);
        my_putstr("\n");
    }
}
