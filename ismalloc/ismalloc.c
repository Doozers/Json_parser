/*
** EPITECH PROJECT, 2022
** defender
** File description:
** No file there , just an epitech header example
*/

#include "../include/ismalloc.h"

static ismalist_t *get_malloc(void *new_head)
{
    static ismalist_t *head = NULL;
    if (new_head)
        return head = new_head;
    return head;
}

static void frisma(void)
{
    ismalist_t *head = get_malloc(NULL);
    void *prev_to_free = head;
    void *head_void = head;
    while (head) {
        if (head->adress)
            free((head->adress));
        head = head->next;
    }
    head = head_void;
    while (head) {
        prev_to_free = head;
        head = head->next;
        free(prev_to_free);
    }
}

void *ismalloc(size_t size)
{
    void *tmp_var = malloc(size);

    ismalist_t *head = get_malloc(NULL);
    ismalist_t *tmp = malloc(sizeof(ismalist_t));
    tmp->next = head;
    tmp->adress = tmp_var;
    get_malloc(tmp);

    return tmp_var;
}
