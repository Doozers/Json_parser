/*
** EPITECH PROJECT, 2021
** my
** File description:
** my_getnbr
*/

int my_getnbr(char const *str)
{
    int z = 0;
    int i = 0;
    int n = 0;

    for (i = 0; str[i] < '0' || str[i] > '9'; i++);
    for (; str[i] >= '0' && str[i] <= '9'; i++) {
        if (i > 0 && str[i - 1] == '-') {
            n = 1;
        }
        z = z * 10;
        z += str[i] - 48;
    }
    if (n == 1)
        return (z * (-1));
    return (z);
}
