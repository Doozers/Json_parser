/*
** EPITECH PROJECT, 2022
** json_parser
** File description:
** No file there , just an epitech header example
*/

#include "include/json_parser.h"

void case_obj(char *str, int *i, obj_t **node)
{
    int profondeur = 0;
    *i += 2;
    do {
        if (str[*i] == '{')
            profondeur++;
        if (str[*i] == '}')
            profondeur--;
        (*node)->value_str = my_strcatchar((*node)->value_str, str[*i]);
        *i += 1;
    } while (profondeur != 0);
}

void case_value(char *str, int *i, obj_t **node)
{
    *i += 2;
    do {
        (*node)->value_str = my_strcatchar((*node)->value_str, str[*i]);
        *i += 1;
    } while (str[*i] && str[*i] != ',' && str[*i] != '}');
    //my_putstr((*node)->value_str);
}

void case_tab(char *str, int *i, obj_t **node)
{
    int profondeur = 0;
    *i += 2;
    do {
        if (str[*i] == '[')
            profondeur++;
        if (str[*i] == ']')
            profondeur--;
        (*node)->value_str = my_strcatchar((*node)->value_str, str[*i]);
        *i += 1;
    } while (profondeur != 0);
}