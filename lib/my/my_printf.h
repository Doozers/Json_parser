/*
** EPITECH PROJECT, 2021
** my
** File description:
** my_printf
*/

#ifndef prinf
    #define prinf

    #include "my.h"
    #include <stdarg.h>

void my_printf(char *str, ...);
int issignal(char car);
int formatageint(int argument, int cutter);
char *formatagechar(char *argument, int cutter);
int formatageuint(unsigned int argument, int cutter);
void verifn(int nb);
void signalselect2(char signal, va_list args, int on, int prenb);
void signalselect6(char signal, va_list args, int on, int prenb);
void signalselect5(char signal, va_list args, int on, int prenb);
void signalselect4(char signal, va_list args, int on, int prenb);
void signalselect3(char signal, va_list args, int on, int prenb);

#endif /* my */
