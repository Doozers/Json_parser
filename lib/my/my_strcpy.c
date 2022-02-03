/*
** EPITECH PROJECT, 2021
** my
** File description:
** my_strcpy
*/

#include <unistd.h>
#include <stdio.h>

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}
