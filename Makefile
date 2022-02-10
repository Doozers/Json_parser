##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Project's main makefile
##

SRC		=	main.c \
			$(wildcard parser/*.c) \
			$(wildcard writer/*.c) \
			$(wildcard ismalloc/*.c)

OBJ		=	$(SRC:.c=.o)

NAME	=	json_parser

CFLAGS 	=	-g3 -Iinclude

LIB		=	-L./lib/my -lmy

LIB2	=	-L./list_lib -llist

${NAME}:	${OBJ}
			make -C./lib/my/
			gcc -o ${NAME} ${OBJ} $(LIB) $(CFLAGS)

all :		${NAME}

clean:
			rm -f ${OBJ}
			rm -f vgcore*
			make clean -C./lib/my

fclean:		clean
			rm -f ${NAME}
			make fclean -C./lib/my/

re:		fclean all

.PHONY: all clean fclean re
