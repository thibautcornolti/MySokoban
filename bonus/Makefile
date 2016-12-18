##
## Makefile for Makefile in /home/thibrex/delivery/CPool_Day10/do-op
## 
## Made by Thibaut Cornolti
## Login   <thibaut.cornolti@epitech.eu>
## 
## Started on  Sat Oct 15 22:12:03 2016 Thibaut Cornolti
## Last update Sun Dec 18 17:33:22 2016 Thibaut Cornolti
##
SRC	=	main.c			\
		load_file.c		\
		utils.c			\
		utils2.c		\
		game.c			\
		menu.c			\
		menu_utils.c		\
		move.c			\
		fct.c			\
		check.c			\
		check_game.c		\
		js.c			\
		editor.c		\
		editor_utils.c		\
		choice_map.c		\
		choice_map_2.c		\
		choice_editor.c		\
		animation.c		\
		music.c			\
		network.c		\
		net_game.c		\

OBJS	=	$(SRCS:.c=.o)

NAME	=	my_sokoban

CC	=	gcc

HEADER	=	include/

RM	=	rm -f

LIB_P	=	-Llib/my

LIB	=	-lmy -lncurses -lm -lfmodL -lcsfml-network -lsfml-graphics -lsfml-window -lcsfml-system

all:	$(NAME)

$(NAME):
	cd lib/my/ && make
	$(CC) -o $(NAME) -I$(HEADER) $(SRC) $(LIB_P) $(LIB) -Wall -Wextra -pedantic -g

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all
