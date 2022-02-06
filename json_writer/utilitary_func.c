/*
** EPITECH PROJECT, 2022
** json_parser
** File description:
** No file there , just an epitech header example
*/

#include "../include/json_parser.h"

int switch_case_func(int in_tab, int fd, int tab, obj_t *tmp)
{
    switch (tmp->data->type) {
        case 'O':
            print_objects(&tmp, tab + 1, fd, in_tab);
            break;
        case 'A':
            print_array(&tmp, tab + 1, fd, in_tab);
            break;
        case 'S':
            print_str(&tmp, tab, fd, in_tab);
            break;
        case 'I':
            print_integer(&tmp, tab, fd, in_tab);
            break;
    }
}

void print_tab(int tab, int fd)
{
    for (int i = tab * 2; i; i--)
        write(fd, " ", 1);
}
