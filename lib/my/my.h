/*
** EPITECH PROJECT, 2021
** my
** File description:
** my
*/

#ifndef my
    #define my
    #include <unistd.h>

void my_putchar(char c);
char *my_strstr(char *str, char const *to_find);
int my_isneg(int nb);
int my_strcmp(char const *s1, char const *s2);
int my_put_nbr(int nb);
int my_strncmp(char const *s1, char const *s2, int n);
void my_swap(int *a, int *b);
char *my_strupcase(char *str);
int my_putstr(char const *str);
char *my_strlowcase(char *str);
int my_strlen(char const *str);
char *my_strcapitalize(char *str);
int my_getnbr(char const *str);
int my_str_isalpha(char const *str);
int my_isnum(char const *str);
int my_compute_power_rec(int nb, int power);
int my_str_islower(char const *str);
int my_compute_square_root(int nb);
int my_str_isupper(char const *str);
int my_is_prime(int nb);
int my_str_isprintable(char const *str);
int my_find_prime_sup(int nb);
int my_showstr(char const *str);
char *my_strcpy(char *dest, char const *src);
int my_showmem(char const *str, int size);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strcat(char *dest, char const *src);
char *my_revstr(char *str);
char *my_strncat(char *dest, char const *src, int nb);
char *my_strdup (char const *src);
char **my_str_to_word_array (char const *str);
int my_getdigit (char digit);
int my_isdigit(char digit);
char *my_strcatchar (char *dest, char const src );
int my_strcmpnb(char *s1, char *s2);
char *rmfirstz(char *str);
int my_isnegati(char *str);
int my_isz(char *str);
char *my_strzwcpy(char *dest, char const *src, int n1, int n2);
int arrondi(double nombre);
void scinot(double nombre);
int my_putfloat(double nombre);
int my_put_nbr2(int nb);
int my_putfloatsci(double nombre);
char *my_intochar(long int nb);
void scinotmaj(double nombre);
int my_put_nbru(unsigned int nb);
char *my_uintochar(unsigned int nb);
char *my_base2(unsigned int nb);
char *my_base(unsigned int nb, char base);
char *allz(char *result);
char *my_basemin(unsigned int nb, char base);
int prints(char *str);
char *my_strcatchardefou(char *dest, char *src);
void my_showarray(char **array);
void my_showarray_c(char **array);
void my_showrevarray_c(char **array);
char  **my_rev_array_c(char **array);
char *my_itoa(long int nb);

#endif/* my */
