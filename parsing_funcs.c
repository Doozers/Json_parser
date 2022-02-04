/*
** EPITECH PROJECT, 2021
** pushswap
** File description:
** pushswap
*/

#include "include/json_parser.h"

obj_t *parsing_object(char *buffer)
{
    obj_t *head = malloc(sizeof(obj_t));
    head->next = NULL;
    head->data = malloc(sizeof(data_t));
    head->data->value = malloc(sizeof(value_t));
    obj_t *node = head;
    char *str = formating_buffer(buffer);
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
            case_value(str, &i, &node, 1);
        } else if (str[i + 2] == '[') { // case tab TODO: coding style
            case_tab(str, &i, &node);
        } else {
            exit(84);
        }
        if (str[i] == '}')
            break;
        obj_t *new_node = malloc(sizeof(obj_t));
        new_node->next = NULL;
        new_node->data = malloc(sizeof(data_t));
        new_node->data->value = malloc(sizeof(value_t));
        node->next = new_node;
        node = node->next;
    }
    parse_each_nodes(&head);
    return head;
}

obj_t *parsing_array(char *buffer)
{
    obj_t *head = malloc(sizeof(obj_t));
    head->next = NULL;
    head->data = malloc(sizeof(data_t));
    head->data->value = malloc(sizeof(value_t));
    obj_t *node = head;
    char *str = formating_buffer(buffer);
    int index = 0;
    for (int i = 1; str[i] != ']'; i++) {
        node->value_str = "\0";
        node->key = my_itoa(index);
        index++;
        if (str[i] == '{') { // case obj
            case_obj(str, &i, &node);
        } else if (str[i] == '"' || my_isdigit(str[i]) == 0) { // case str && int
            case_value(str, &i, &node, 0);
        } else if (str[i] == '[') { // case tab TODO: coding style
            case_tab(str, &i, &node);
        } else {
            exit(84);
        }
        if (str[i] && (str[i] == ']'))
            break;
        obj_t *new_node = malloc(sizeof(obj_t));
        new_node->next = NULL;
        new_node->data = malloc(sizeof(data_t));
        new_node->data->value = malloc(sizeof(value_t));
        node->next = new_node;
        node = node->next;
    }
    parse_each_nodes(&head);
    return head;
}

char *parsing_str(char *buffer)
{
    char *str = malloc(sizeof(buffer));

    for (int i = 1; buffer[i + 1]; i++)
        str = my_strcatchar(str, buffer[i]);

    return str;
}

void parse_each_nodes(obj_t **head)
{
    obj_t *node = *head;
    while (node) {
        if (node->value_str[0] == '{')
            node->data->value->value_obj = parsing_object(node->value_str);
        if (node->value_str[0] == '[')
            node->data->value->value_obj = parsing_array(node->value_str);
        if (node->value_str[0] == '"')
            node->data->value->value_str = parsing_str(node->value_str);
        if (my_isdigit(node->value_str[0]) == 0)
            node->data->value->value_int = my_getnbr(node->value_str);
        node = node->next;
    }
}
