##
## Makefile for Makefile in /home/thibrex/delivery/CPool_Day10/lib/my
## 
## Made by Thibaut Cornolti
## Login   <thibaut.cornolti@epitech.eu>
## 
## Started on  Fri Oct 14 09:19:13 2016 Thibaut Cornolti
## Last update Fri Dec  2 08:23:13 2016 Thibaut Cornolti
##

SRC	=	my_putchar.c		\
		my_puterror.c		\
		convert_base.c		\
		my_fact_rec.c		\
		my_find_prime_sup.c	\
		my_getnbr_base.c	\
		my_getnbr.c		\
		my_isneg.c		\
		my_is_prime.c		\
		my_power_rec.c		\
		my_putnbr_base.c	\
		my_put_nbr.c		\
		my_putstr.c		\
		my_putnstr.c		\
		my_revstr.c		\
		my_showstr.c		\
		my_show_wordtab.c	\
		my_sort_int_tab.c	\
		my_sort_str_tab.c	\
		my_square_root.c	\
		my_strcapitalize.c	\
		my_strcat.c		\
		my_strcmp.c		\
		my_stricmp.c		\
		my_strcpy.c		\
		my_strdup.c		\
		my_str_isalpha.c	\
		my_str_islower.c	\
		my_str_isnum.c		\
		my_str_isprintable.c	\
		my_str_isupper.c	\
		my_strlen.c		\
		my_strtablen.c		\
		my_strlowcase.c		\
		my_strncat.c		\
		my_strncmp.c		\
		my_strncpy.c		\
		my_strstr.c		\
		my_str_to_wordtab.c	\
		my_strupcase.c		\
		my_swap.c		\
		my_memset.c		\
		my_memset_str.c		\
		my_int_to_str.c		\
		my_str_contains.c	\
		my_char_isfactor.c

OBJ	=	$(SRC:.c=.o)

RM	=	rm -f

MV	=	mv

CP	=	cp

CC	=	gcc

AR	=	ar rc

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -w -c $(SRC) -Wall -pedantic
	$(AR) $(NAME) $(OBJ)
	$(RM) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all
