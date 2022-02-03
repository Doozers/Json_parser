/*
** EPITECH PROJECT, 2022
** linked_list
** File description:
** No file there , just an epitech header example
*/

#include "../include/json_parser.h"

void apply_on_place(int place, obj_t **head, int data_modifier)
{
    obj_t *tmp = *head;

    for (int i = 1; i < place; i++)
        tmp = tmp->next;
    tmp->bool = 1;
}

void apply_under_cond(obj_t **head)
{
    obj_t *tmp = *head;
    while (tmp) {
        if (/* exemple */ tmp->data % 2 == 0) // place your cond here
            tmp->bool = 1;
        tmp = tmp->next;
    }
}