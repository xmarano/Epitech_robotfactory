##
## EPITECH PROJECT, 2024
## B-CPE-200-MAR-2-1-robotfactory-arnaud.jouan
## File description:
## Makefile
##

SRCLIB	=	lib/my_atoi.c 		\
			lib/my_intlen.c 	\
			lib/my_printf.c		\
			lib/my_put_nbr_recursive.c	\
			lib/my_put_nbr.c 	\
			lib/my_putchar.c	\
			lib/my_putstr.c		\
			lib/my_strcat.c		\
			lib/my_strcmp.c		\
			lib/my_strcpy.c		\
			lib/my_strdup.c 	\
			lib/my_strlen.c 	\
			lib/my_strncpy.c 	\
			lib/str_to_word_array.c 	\

SRCNAME	=	main.c				\
			error_handling.c	\
			error_body.c		\
			file_to_header.c	\
			core_file.c			\

LIB 	=	libmy.a

OBJLIB	=	$(SRCLIB:.c=.o)

OBJNAME	=	$(SRCNAME:.c=.o)

NAME	=	asm

$(NAME) : 	$(LIB) $(OBJNAME)
			gcc -o $(NAME) $(OBJNAME) -lmy -L./ -g3

$(LIB) 	: 	$(OBJLIB)
			ar rc libmy.a lib/*.o

all		:	$(LIB) $(NAME)

clean	:
			rm -f $(OBJLIB) $(OBJNAME) libmy.a

fclean	:	clean
			rm -f $(NAME)

re		: 	fclean all
