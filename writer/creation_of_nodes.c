/*
** EPITECH PROJECT, 2022
** defender
** File description:
** No file there , just an epitech header example
*/

#include "../include/json_parser.h"

obj_t *new_object(obj_t **neck, char *key)
{
    obj_t *head;
    if (!(*neck)) {
        head = ismalloc(sizeof(obj_t));
        head->next = NULL;
    } else
        head = *neck;
    while (head->next) head = head->next;
    head->next = ismalloc(sizeof(obj_t));
    head = head->next;
    head->next = NULL;
    head->data = ismalloc(sizeof(data_t));
    head->data->value = ismalloc(sizeof(value_t));
    head->key = key;
    head->data->type = 'O';
    head->data->value->value_obj = NULL;
    if (!(*neck))
        (*neck) = head;
    return head;
}

void add_str(obj_t **base_object, char *key, char *data)
{
    obj_t *tmp = *base_object;
    if (!tmp->data->value->value_obj) {
        tmp->data->value->value_obj = ismalloc(sizeof(obj_t));
        tmp = tmp->data->value->value_obj;
    } else {
        tmp = tmp->data->value->value_obj;
        while (tmp->next) tmp = tmp->next;
        tmp->next = ismalloc(sizeof(obj_t));
        tmp = tmp->next;
    }
    tmp->next = NULL;
    tmp->data = ismalloc(sizeof(data_t));
    tmp->data->value = ismalloc(sizeof(value_t));
    tmp->key = key;
    tmp->data->type = 'S';
    tmp->data->value->value_str = data;
}

void add_int(obj_t **base_object, char *key, int data)
{
    obj_t *tmp = *base_object;
    if (!tmp->data->value->value_obj) {
        tmp->data->value->value_obj = ismalloc(sizeof(obj_t));
        tmp = tmp->data->value->value_obj;
    } else {
        tmp = tmp->data->value->value_obj;
        while (tmp->next) tmp = tmp->next;
        tmp->next = ismalloc(sizeof(obj_t));
        tmp = tmp->next;
    }
    tmp->next = NULL;
    tmp->data = ismalloc(sizeof(data_t));
    tmp->data->value = ismalloc(sizeof(value_t));
    tmp->key = key;
    tmp->data->type = 'I';
    tmp->data->value->value_int = data;
}
