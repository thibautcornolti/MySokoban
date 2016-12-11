##
## Makefile for Makefile in /home/thibrex/delivery/CPool_Day10/do-op
## 
## Made by Thibaut Cornolti
## Login   <thibaut.cornolti@epitech.eu>
## 
## Started on  Sat Oct 15 22:12:03 2016 Thibaut Cornolti
## Last update Sun Dec 11 21:16:25 2016 Thibaut Cornolti
##
SRC	=	main.c			\
		load_file.c		\
		utils.c			\
		game.c			\
		move.c			\
		fct.c			\
		check.c			\
		check_game.c		\
		js.c			\

OBJS	=	$(SRCS:.c=.o)

NAME	=	my_sokoban

CC	=	gcc

HEADER	=	include/

RM	=	rm -f

LIB_P	=	-Llib/my

LIB	=	-lmy -lncurses

all:	$(NAME)

$(NAME):
	cd lib/my/ && make
	$(CC) -o $(NAME) -I$(HEADER) $(SRC) $(LIB_P) $(LIB) -Wall -Wextra -pedantic -g

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all
