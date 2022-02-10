# Json_parser in C 

This is a Json parser create from scratch, only using the `malloc()` and `free()` functions from the C librairie.
I made it as I can use a proper and common data structure in my Epitech's projects.

## USAGE 

> #### To get the json in a structured linked list:

```C
obj_t *json_parser(char *json_to_open);
```
> #### To access a node in a list :

```C
obj_t *acces_node(obj_t **coming, char *str); // ex : str = "data/adress_data/Chicago/Mr_X"
```

> #### To write a list in a .json file :

```C
void json_writer(obj_t *head, char *file);
```

> ### To create easly a new node in the func :

```C
obj_t *new_object(obj_t **neck, char *key); /* neck is the key of an object in the linked list where you want to
add the new object */
```
