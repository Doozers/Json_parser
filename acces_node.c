/*
** EPITECH PROJECT, 2022
** json_parser
** File description:
** No file there , just an epitech header example
*/

#include "include/json_parser.h"
#include <string.h>

int count_slash(char *str)
{
    int index = 1;
    for (int i = 0; str[i]; i++)
        if (str[i] == '/')
            index++;

    return index;
}

char **parsing_access(char *str)
{
    int size_tab = count_slash(str);
    char **array = malloc(sizeof(char *) * (size_tab + 1));
    int index_tab = 0;
    array[0] = "\0";

    for (int i = 0; str[i]; i++) {
        if (str[i] == '/') {
            index_tab++;
            array[index_tab] = "\0";
            continue;
        }
        array[index_tab] = my_strcatchar(array[index_tab], str[i]);
    }
    array[size_tab] = NULL;

    return array;
}

obj_t *acces_node(obj_t **coming, char *str)
{
    obj_t *head = *coming;
    char **array = parsing_access(str);

    for (int i = 0; array[i]; i++) {
        while (strcmp(head->key, array[i]) != 0) head = head->next;
        if (array[i + 1])
            head = head->data->value->value_obj;
    }

    return head;
}
