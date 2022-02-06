/*
** EPITECH PROJECT, 2022
** json_parser
** File description:
** No file there , just an epitech header example
*/

#include "../include/json_parser.h"

void json_writer(obj_t *head, char *file)
{
    int tab = 0;
    int fd = open(file, O_WRONLY);
    write(fd, "{", 1);
    tab++;
    while (head) {
        print_objects(&head, tab + 1, fd, 0);
        head = head->next;
        if (head)
            write(fd, ",", 1);
    }
    write(fd, "\n}", 2);
    close(fd);
}
