/*
** EPITECH PROJECT, 2021
** include
** File description:
** pushswap
*/

#ifndef include
    #define include

    #include "my.h"
    #include "stdlib.h"
    #include "stdio.h"
    #include "unistd.h"
    #include "fcntl.h"
    #include "sys/stat.h"

typedef union value {
    char *tag;
    int value_int;
    char *value_str;
    char **value_array;
    struct obj *value_obj;
} value_t;

typedef struct data {
    union value *value;
    struct data *next;
} data_t;

typedef struct obj {
    char *key;
    char *value_str;
    struct data *data;
    struct obj *next;
} obj_t;

//main.h
void my_show_list(obj_t *node);

//parsing_funcs.h
obj_t *parsing_object(char *buffer);
char **parsing_array(char *str);
void parse_each_nodes(obj_t **head);

//formating_funcs.h
char *formating_buffer(char *buffer);

// counter.h
int count_tab(char *str);

//diff_case_parsing.h
void case_obj(char *str, int *i, obj_t **node);
void case_value(char *str, int *i, obj_t **node);
void case_tab(char *str, int *i, obj_t **node);

#endif /* include */
