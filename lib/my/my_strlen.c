/*
** EPITECH PROJECT, 2021
** my
** File description:
** my_strlen
*/

#include <unistd.h>

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return (i);
}
