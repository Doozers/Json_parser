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
    #include "ismalloc.h"

typedef union value {
    int value_int;
    char *value_str;
    struct obj *value_obj;
} value_t;

typedef struct data {
    char type;
    union value *value;
} data_t;

typedef struct obj {
    char *key;
    char *value_str;
    struct data *data;
    struct obj *next;
} obj_t;

//main.h
obj_t *json_parser(char *json_to_open);
void my_show_list(obj_t *node);

//parsing_funcs.h
obj_t *parsing_object(char *buffer);
obj_t *parsing_array(char *str);
void parse_each_nodes(obj_t **head);

//formating_funcs.h
char *formating_buffer(char *buffer);

// counter.h
int count_tab(char *str);

//diff_case_parsing.h
void case_obj(char *str, int *i, obj_t **node, int bool);
void case_value(char *str, int *i, obj_t **node, int is_tab);
void case_tab(char *str, int *i, obj_t **node);

//access_node.h
obj_t *acces_node(obj_t **coming, char *str);

//parsing_funcs_annexe.h
obj_t *parsing_object(char *buffer);
void annex_parsing_array(obj_t **node, char *str, int *i, int *index);
void annexe_parsing_object(obj_t **node, char *str, int *i);

//json_writer.h
void json_writer(obj_t *head, char *file);

//printer_cases.h
void print_objects(obj_t **head, int tab, int fd, int in_tab);
void print_array(obj_t **head, int tab, int fd, int in_tab);
void print_str(obj_t **head, int tab, int fd, int in_tab);
void print_integer(obj_t **head, int tab, int fd, int in_tab);

//utilitary_func.h
void print_tab(int tab, int fd);
int switch_case_func(int in_tab, int fd, int tab, obj_t *tmp);

//creation_of_nodes.h
obj_t *new_object(obj_t **neck, char *key);
void add_str(obj_t **base_object, char *key, char *data);
void add_int(obj_t **base_object, char *key, int data);

#endif /* include */
