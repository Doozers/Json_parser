/*
** EPITECH PROJECT, 2021
** Bistro
** File description:
** No file there , just an epitech header example
*/

#include "my.h"

char *my_itoa(long int nb)
{
    long int p = 1;
    int to_print;
    int to_keep;
    char *result = "\0";
    if (nb < 0) {
        result = my_strcatchar(result, '-');
        nb = nb * (-1);
    }
    while (p * 10 <= nb) {
        p = p * 10;
    }
    to_keep = nb;
    while (p > 1) {
        to_print = to_keep / p;
        to_keep = to_keep % p;
        p = p / 10;
        result = my_strcatchar(result, to_print + '0');
    }
    result = my_strcatchar(result, to_keep + '0');
    return result;
}
