/*
** EPITECH PROJECT, 2022
** linked_list
** File description:
** No file there , just an epitech header example
*/

#include "../include/json_parser.h"

void add_on_top(obj_t **head, int data)
{
    obj_t *node = malloc(sizeof(obj_t));

    node->data = data;
    node->next = *head;
    *head = node;
}

void add_on_bot( **head, int data)
{
    obj_t *tmp = *head;
    obj_t *node = malloc(sizeof(obj_t));

    node->data = data;
    node->next = NULL;
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = node;
}

void add_on_place(int place, obj_t **head, int data)
{
    obj_t *tmp = *head;
    obj_t *node = malloc(sizeof(obj_t));

    node->data = data;
    node->next = NULL;
    for (int i = 2; i < place; i++)
        tmp = tmp->next;
    void *save_next = tmp->next;
    tmp->next = node;
    node->next = save_next;
}