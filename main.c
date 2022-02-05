/*
** EPITECH PROJECT, 2021
** pushswap
** File description:
** pushswap
*/

#include "include/json_parser.h"
#include <string.h>

void my_show_list(obj_t *node)
{
    while (node) {
        printf("key: %s && value is = %s\n", node->key, node->value_str);
        node = node->next;
    }
}

obj_t *json_parser(char *json_to_open)
{
    int f = open(json_to_open, O_RDONLY);
    struct stat stat1;

    stat(json_to_open, &stat1);
    char buffer[stat1.st_size];
    read(f, buffer, stat1.st_size);
    buffer[stat1.st_size] = '\0';
    obj_t *head = parsing_object(buffer);

    printf("voila = %i", acces_node(&head, "tower3/pos/0")->data->value->value_int);

    return head;
}

int main(int ac, char **av)
{
    obj_t *h = json_parser("exemple.json");
}
