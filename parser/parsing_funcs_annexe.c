/*
** EPITECH PROJECT, 2022
** json_parser
** File description:
** No file there , just an epitech header example
*/

#include "../include/json_parser.h"

void annexe_parsing_object(obj_t **node, char *str, int *i)
{
    (*node)->key = "\0";
    (*node)->value_str = "\0";
    if (str[*i] == '\"') {
        *i += 1;
        for (; str[*i] != '\"'; *i += 1)
            (*node)->key = my_strcatchar((*node)->key, str[*i]);
    }
    if (str[*i + 2] == '{') {
        case_obj(str, i, node, 1);
    } else if (str[*i + 2] == '"' || my_isdigit(str[*i + 2]) == 0) {
        case_value(str, i, node, 1);
    } else
        case_tab(str, i, node);
}

void annex_parsing_array(obj_t **node, char *str, int *i, int *index)
{
    (*node)->value_str = "\0";
    (*node)->key = my_itoa(*index);
    *index += 1;
    if (str[*i] == '{') {
        case_obj(str, i, node, 0);
    } else if (str[*i] == '"' || my_isdigit(str[*i]) == 0) {
        case_value(str, i, node, 0);
    } else
        case_tab(str, i, node);
}
