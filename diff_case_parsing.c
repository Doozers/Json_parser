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

void case_value(char *str, int *i, obj_t **node, int is_tab)
{
    if (is_tab == 1)
        *i += 2;
    do {
        (*node)->value_str = my_strcatchar((*node)->value_str, str[*i]);
        *i += 1;
        if (is_tab == 0 && str[*i] == ']')
            break;
    } while (str[*i] && str[*i] != ',' && str[*i] != '}');
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