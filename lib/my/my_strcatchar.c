/*
** EPITECH PROJECT, 2021
** B-CPE-100-LYN-1-1-cpoolday09-ismael.fall
** File description:
** my_strcatchar
*/

#include <stdlib.h>

char *my_strcpy(char *dest, char const *src);
int my_strlen(char const *str);

char *my_strcatchar(char *dest, char const src)
{
    int i = my_strlen(dest);

    char *returned;
    returned = malloc(sizeof(char) * (i + 2));
    returned = my_strcpy(returned, dest);
    returned[i] = src;
    returned[i + 1] = '\0';
    return (returned);
}
