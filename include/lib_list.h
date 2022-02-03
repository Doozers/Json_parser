/*
** EPITECH PROJECT, 2021
** include
** File description:
** pushswap
*/

#ifndef lib_list
    #define lib_list

    #include "json_parser.h"

list_t *decla_list(void);

list_t *decla_list_with_tab(char **tab);

void add_on_top(list_t **head, int data);

void add_on_bot(list_t **head, int data);

void add_on_place(int place, list_t **head, int data);

void apply_on_place(int place, list_t **head, int data_modifier);

void apply_under_cond(list_t **head);

char **create_tab_with_list(list_t *head);

char *create_str_with_list(list_t *head);

list_t *decla_list_with_str(char *tab);

void delete_on_top(list_t **head);

void delete_on_bot(list_t **head);

void delete_on_place(int place, list_t **head);

void delete_under_cond(list_t **head);

void **get_nodes_under_cond(list_t **head); // need to be optimized

void acces_node_tab(void **node_tab);

list_t *new_list_with_node_tab(void **node_tab);

#endif /* lib_list */
