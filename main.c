/*
** EPITECH PROJECT, 2021
** pushswap
** File description:
** pushswap
*/

#include "json_parser.h"

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

    return head;
}

int main(int ac, char **av)
{
    obj_t *h = json_parser("exemple.json");
    obj_t *tmp = acces_node(&h, "tower2/level");
                                                                                                                                                                                                                                                                                                                       tmp->data->value->value_int = 257;
    printf("voila = %i\n", acces_node(&h, "tower3/pos/0")->data->value->value_int);
    json_writer(h, "output.json");
}
