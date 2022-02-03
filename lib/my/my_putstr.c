/*
** EPITECH PROJECT, 2021
** my
** File description:
** my_putstr
*/

#include <unistd.h>

void my_putchar(char c);

int my_putstr(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        my_putchar(str[i]);
    return 0;
}
