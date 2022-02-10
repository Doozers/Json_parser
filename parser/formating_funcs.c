/*
** EPITECH PROJECT, 2022
** json_parser
** File description:
** No file there , just an epitech header example
*/

#include "json_parser.h"

char *formating_buffer(char *buf)
{
    char *formated = "\0";
    int deep = 0;
    int check = 0;
    for (int i = 0; buf[i]; i++) {
        check = 0;
        if (deep == 0 && buf[i] == '"') {
            deep++;
            check = 1;
        }
        if (check == 0 && (deep == 1 && buf[i] == '"'))
            deep--;
        if (buf[i] != '\n' && (buf[i] != '\t' && buf[i] != ' ' || deep == 1))
            formated = my_strcatchar(formated, buf[i]);
    }
    return formated;
}
