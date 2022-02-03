/*
** EPITECH PROJECT, 2022
** json_parser
** File description:
** No file there , just an epitech header example
*/

#include "include/json_parser.h"

char *formating_buffer(char *buffer)
{
    char *formated = "\0";
    int deepness = 0;
    for (int i = 0; buffer[i]; i++) {
        if (deepness == 0 && buffer[i] == '"')
            deepness++;
        else if (deepness == 1 && buffer[i] == '"')
            deepness--;
        if (buffer[i] != '\n' && (buffer[i] != '\t' && buffer[i] != ' ' || deepness == 1))
            formated = my_strcatchar(formated, buffer[i]);
    }
    return formated;
}
