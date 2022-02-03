/*
** EPITECH PROJECT, 2022
** linked_list
** File description:
** No file there , just an epitech header example
*/

#include "../include/json_parser.h"

obj_t *decla_list(void)
{
    int counter = 0;
    obj_t *node = malloc(sizeof(obj_t));
    void *head = node;

    node->data = counter;
    counter++;
    node->next = NULL;
    while (counter < 6) {
        node->next = malloc(sizeof(obj_t));
        node = node->next;
        node->data = counter;
        node->next = NULL;
        counter++;
    }
    return head;
}

 *decla_list_with_tab(char **tab)
{
    obj_t *node = malloc(sizeof(obj_t));
    void *head = node;

    node->data = my_getnbr(tab[0]);
    node->next = NULL;
    for (int i = 1; tab[i]; i++) {
        node->next = malloc(sizeof(obj_t));
        node = node->next;
        node->data = my_getnbr(tab[i]);
        node->next = NULL;
    }
    return head;
}

 *decla_list_with_str(char *tab)
{
    obj_t *node = malloc(sizeof(obj_t));
    void *head = node;

    node->data = my_getdigit(tab[0]);
    node->next = NULL;
    for (int i = 1; tab[i]; i++) {
        node->next = malloc(sizeof(obj_t));
        node = node->next;
        node->data = my_getdigit(tab[i]);
        node->next = NULL;
    }
    return head;
}
