##
## Makefile for Makefile in /home/thibrex/delivery/CPool_Day10/do-op
## 
## Made by Thibaut Cornolti
## Login   <thibaut.cornolti@epitech.eu>
## 
## Started on  Sat Oct 15 22:12:03 2016 Thibaut Cornolti
## Last update Tue Dec 20 14:50:03 2016 Thibaut Cornolti
##
SRC	=	main.c				\
		utils/load_file.c		\
		utils/utils.c			\
		utils/utils2.c			\
		game/game.c			\
		menu/menu.c			\
		menu/menu_utils.c		\
		game/move.c			\
		game/fct.c			\
		check/check.c			\
		check/check_game.c		\
		misc/js.c			\
		editor/editor.c			\
		editor/editor_utils.c		\
		manager/choice_map.c		\
		manager/choice_map_2.c		\
		manager/choice_editor.c		\
		misc/animation.c		\
		misc/music.c			\
		network/network.c		\
		network/net_game.c		\

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
