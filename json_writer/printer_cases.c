/*
** EPITECH PROJECT, 2022
** json_parser
** File description:
** No file there , just an epitech header example
*/

#include "../include/json_parser.h"

void print_integer(obj_t **head, int tab, int fd, int in_tab)
{
    write(fd, "\n", 1);
    print_tab(tab, fd);
    if (!in_tab) {
        write(fd, "\"", 1);
        write(fd, (*head)->key, my_strlen((*head)->key));
        write(fd, "\": ", 3);
    }
    write(fd, my_itoa((*head)->data->value->value_int),
    my_strlen(my_itoa((*head)->data->value->value_int)));
}

void print_str(obj_t **head, int tab, int fd, int in_tab)
{
    write(fd, "\n", 1);
    print_tab(tab, fd);
    if (!in_tab) {
        write(fd, "\"", 1);
        write(fd, (*head)->key, my_strlen((*head)->key));
        write(fd, "\": ", 3);
    }
    write(fd, "\"", 1);
    write(fd, (*head)->data->value->value_str,
    my_strlen((*head)->data->value->value_str));
    write(fd, "\"", 1);
}

void print_array(obj_t **head, int tab, int fd, int in_tab)
{
    obj_t *tmp = (*head)->data->value->value_obj;
    write(fd, "\n", 1);
    print_tab(tab - 1, fd);
    if (!in_tab) {
        write(fd, "\"", 1);
        write(fd, (*head)->key, my_strlen((*head)->key));
        write(fd, "\": ", 3);
    }
    write(fd, "[", 1);
    while (tmp) {
        switch_case_func(1, fd, tab, tmp);
        tmp = tmp->next;
        if (tmp)
            write(fd, ",", 1);
    }
    write(fd, "\n", 1);
    print_tab(tab - 1, fd);
    write(fd, "]", 1);
}

void print_objects(obj_t **head, int tab, int fd, int in_tab)
{
    obj_t *tmp = (*head)->data->value->value_obj;
    write(fd, "\n", 1);
    print_tab(tab - 1, fd);
    if (!in_tab) {
        write(fd, "\"", 1);
        write(fd, (*head)->key, my_strlen((*head)->key));
        write(fd, "\": ", 3);
    }
    write(fd, "{", 1);
    while (tmp) {
        switch_case_func(0, fd, tab, tmp);
        tmp = tmp->next;
        if (tmp)
            write(fd, ",", 1);
    }
    write(fd, "\n", 1);
    print_tab(tab - 1, fd);
    write(fd, "}", 1);
}
