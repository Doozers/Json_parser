/*
** EPITECH PROJECT, 2022
** linked_list
** File description:
** No file there , just an epitech header example
*/

#include "../include/json_parser.h"

void **get_nodes_under_cond(obj_t **head) // need to be optimized
{
    obj_t *tmp = *head;
    int nb_matching = 0;
    int index_tab = 0;
    for (int i = 0; tmp; i++) {
        if ( /* exemple */ tmp->data % 2 == 0) // place your cond here
            nb_matching++;
        tmp = (tmp)->next;
    }
    tmp = *head;
    void **matching_nodes = malloc(sizeof(void *) * (nb_matching + 1));
    for (int i = 0; tmp; i++) {
        if ( /* exemple */ tmp->data % 2 == 0) { // place your cond here
            matching_nodes[index_tab] = tmp;
            index_tab++;
        }
        tmp = (tmp)->next;
    }
    matching_nodes[index_tab] = NULL;

    return matching_nodes;
}

void acces_node_tab(void **node_tab)
{
    obj_t *tmp;

    for (int i = 0; node_tab[i]; i++) {
        tmp = node_tab[i];
        printf("is matching : %i\n", tmp->data);
    }
}