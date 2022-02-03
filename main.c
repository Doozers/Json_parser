/*
** EPITECH PROJECT, 2021
** pushswap
** File description:
** pushswap
*/

#include "include/json_parser.h"

void my_show_list(obj_t *node)
{
    while (node) {
        printf("key: %s && value is = %s\n", node->key, node->value_str);
        node = node->next;
    }
}

int main(int ac, char const **av)
{
    int f = open("exemple.json", O_RDONLY);
    struct stat stat1;
    stat("exemple.json", &stat1);

    char buffer[stat1.st_size];

    read(f, buffer, stat1.st_size);
    buffer[stat1.st_size] = '\0';
    obj_t *head = parsing_object(buffer);
    parse_each_nodes(&head);
}