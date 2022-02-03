/*
** EPITECH PROJECT, 2021
** pushswap
** File description:
** pushswap
*/

#include "include/json_parser.h"

char **parsing_array(char *str)
{
    int index_tab = 0;
    int size_tab = count_tab(str);
    char **array = malloc(sizeof(char *) * size_tab + 1);
    array[size_tab] = NULL;
    array[index_tab] = "\0";

    for (int i = 1; str[i] != ']'; i++) {
        if (str[i] == ',') {
            index_tab++;
            array[index_tab] = "\0";
        } else
            array[index_tab] = my_strcatchar(array[index_tab], str[i]);
    }
    my_showarray(array);

    return array;
}

obj_t *parsing_object(char *buffer)
{
    obj_t *head = malloc(sizeof(obj_t));
    head->data = malloc(sizeof(data_t));
    head->data->value = malloc(sizeof(value_t));
    obj_t *node = head;
    char *str = formating_buffer(buffer);
    //printf("%s\n", str);
    for (int i = 1; str[i] != '}'; i++) {
        node->key = "\0";
        node->value_str = "\0";
        if (str[i] == '\"') {
            i++;
            for (; str[i] != '\"'; i++)
                node->key = my_strcatchar(node->key, str[i]);
        }
        if (str[i + 2] == '{') { // case obj
            case_obj(str, &i, &node);
        } else if (str[i + 2] == '"' || my_isdigit(str[i + 2]) == 0) { // case str && int
            case_value(str, &i, &node);
        } else if (str[i + 2] == '[') { // case tab TODO: coding style
            case_tab(str, &i, &node);
        } else {
            my_show_list(head);
            printf("\n%c is %c && i = %i\n", str[i + 2], str[i + 3], i);
            exit(84);
        }
        if (str[i] == '}')
            break;
        obj_t *new_node = malloc(sizeof(obj_t));
        new_node->data = malloc(sizeof(data_t));
        new_node->data->value = malloc(sizeof(value_t));
        node->next = new_node;
        node = node->next;
    }
    my_show_list(head);
    printf("\n\n");
    return head;
}

void parse_each_nodes(obj_t **head)
{
    obj_t *node = *head;
    while (node) {
        switch (node->value_str[0]) {
            case '{':
                node->data->value->value_obj = parsing_object(node->value_str);
                break;
        }
        node = node->next;
    }
    //my_show_list(*head);
}
