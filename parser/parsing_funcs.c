/*
** EPITECH PROJECT, 2021
** pushswap
** File description:
** pushswap
*/

#include "../include/json_parser.h"

obj_t *parsing_object(char *buffer)
{
    obj_t *head = ismalloc(sizeof(obj_t));
    head->data = ismalloc(sizeof(data_t));
    head->data->value = ismalloc(sizeof(value_t));
    head->next = NULL;
    obj_t *node = head;
    char *str = formating_buffer(buffer);
    for (int i = 1; str[i] != '}'; i++) {
        annexe_parsing_object(&node, str, &i);
        if (str[i] == '}')
            break;
        obj_t *new_node = ismalloc(sizeof(obj_t));
        new_node->data = ismalloc(sizeof(data_t));
        new_node->data->value = ismalloc(sizeof(value_t));
        new_node->next = NULL;
        node->next = new_node;
        node = node->next;
    }
    parse_each_nodes(&head);
    return head;
}

obj_t *parsing_array(char *buffer)
{
    obj_t *head = ismalloc(sizeof(obj_t));
    head->data = ismalloc(sizeof(data_t));
    head->data->value = ismalloc(sizeof(value_t));
    head->next = NULL;
    obj_t *node = head;
    char *str = formating_buffer(buffer);
    int index = 0;
    for (int i = 1; str[i] != ']'; i++) {
        annex_parsing_array(&node, str, &i, &index);
        if (str[i] && (str[i] == ']'))
            break;
        obj_t *new_node = ismalloc(sizeof(obj_t));
        new_node->data = ismalloc(sizeof(data_t));
        new_node->data->value = ismalloc(sizeof(value_t));
        new_node->next = NULL;
        node->next = new_node;
        node = node->next;
    }
    parse_each_nodes(&head);
    return head;
}

char *parsing_str(char *buffer)
{
    char *str = "\0";

    for (int i = 1; buffer[i] && buffer[i + 1]; i++)
        str = my_strcatchar(str, buffer[i]);

    return str;
}

void parse_each_nodes(obj_t **head)
{
    obj_t *node = *head;
    while (node) {
        if (node->value_str[0] == '{') {
            node->data->value->value_obj = parsing_object(node->value_str);
            node->data->type = 'O';
        }
        if (node->value_str[0] == '[') {
            node->data->value->value_obj = parsing_array(node->value_str);
            node->data->type = 'A';
        }
        if (node->value_str[0] == '"') {
            node->data->value->value_str = parsing_str(node->value_str);
            node->data->type = 'S';
        }
        if (my_isdigit(node->value_str[0]) == 0) {
            node->data->value->value_int = my_getnbr(node->value_str);
            node->data->type = 'I';
        }
        node = node->next;
    }
}
