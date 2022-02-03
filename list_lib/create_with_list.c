/*
** EPITECH PROJECT, 2022
** linked_list
** File description:
** No file there , just an epitech header example
*/

#include "../include/json_parser.h"

char **create_tab_with_list(obj_t *head)
{
    obj_t *tmp = head;
    int len_tab = 0;
    int i;

    for (len_tab = 1; tmp->next; len_tab++)
        tmp = (tmp)->next;
    tmp = head;
    char **tab = malloc(sizeof(char *) * (len_tab + 1));

    for (i = 0; tmp; i++) {
        tab[i] = my_strdup(my_itoa(tmp->data));
        tmp = tmp->next;
    }
    tab[i] = NULL;
    return tab;
}

char *create_str_with_list( *head)
{
    obj_t *tmp = head;
    int len_str = 0;
    int i;

    for (len_str = 1; tmp->next; len_str++)
        tmp = (tmp)->next;
    tmp = head;

    char *str = malloc(sizeof(char *) * (len_str + 1));

    for (i = 0; tmp; i++) {
        str[i] = my_itoa(tmp->data)[0]; //  suppr getdigit if str need to contain characters
        tmp = tmp->next;
    }
    str[i] = '\0';

    return str;
}