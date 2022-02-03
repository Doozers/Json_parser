/*
** EPITECH PROJECT, 2022
** linked_list
** File description:
** No file there , just an epitech header example
*/

#include "../include/json_parser.h"

void delete_on_top(obj_t **head)
{
    *head = (*head)->next;
}

void delete_on_bot( **head)
{
    obj_t *tmp = *head;

    while ((tmp->next)->next)
        tmp = tmp->next;
    tmp->next = NULL;
}
void delete_under_cond( **head)
{
    obj_t *tmp = malloc(sizeof(obj_t));
    int check = 0;

    tmp->next = *head;
    while (tmp) {
        int can_pass = 1;
        if (/* exemple */ tmp->next && (tmp->next)->data % 2 == 0) { // place your cond here
            tmp->next = (tmp->next)->next;
            can_pass--;
        } else if (check == 0) {
            *head = tmp->next;
            check = 1;
        }
        if (can_pass)
            tmp = tmp->next;
    }
}

void delete_on_place(int place,  **head) // for the first node use "delete_ont_top"
{
    obj_t *tmp = *head;

    for (int i = 2; i < place; i++)
        tmp = tmp->next;
    tmp->next = (tmp->next)->next;
}

 *new_list_with_node_tab(void **node_tab)
{
    obj_t *node = malloc(sizeof());
    obj_t *tab_case = node_tab[0];
    void *head = node;

    node->data = tab_case->data;
    node->next = NULL;
    for (int i = 1; node_tab[i]; i++) {
        tab_case = node_tab[i];
        node->next = malloc(sizeof());
        node = node->next;
        node->data = tab_case->data;
        node->next = NULL;
    }
    return head;
}