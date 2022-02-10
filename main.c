/*
** EPITECH PROJECT, 2021
** pushswap
** File description:
** pushswap
*/

#include "../include/json_parser.h"

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
    obj_t *head = json_parser("exemple.json");
    obj_t *tmp = acces_node(&head, "data/adress_data/Chicago/Mr_B");

    tmp->data->value->value_str = "EPITECH Lyon 69007";
    tmp = acces_node(&head, "data/politics_data/nb vote 3 last years");
    tmp = new_object(&tmp, "GRADE");
    add_int(&tmp, "GPA", 3);
    add_str(&tmp, "#_#", "-_-");

    json_writer(head, "output.json");
}
