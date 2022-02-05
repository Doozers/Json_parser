/*
** EPITECH PROJECT, 2022
** json_parser
** File description:
** No file there , just an epitech header example
*/

int count_tab(char *str)
{
    int size_tab = 1;
    for (int i = 0; str[i]; i++)
        if (str[i] == ',')
            size_tab++;

    return size_tab;
}
