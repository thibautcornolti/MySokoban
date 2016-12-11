/*
** soko.h for my_sokoban in /home/thibrex/delivery/PSU/PSU_2016_my_sokoban
** 
** Made by Thibaut Cornolti
** Login   <thibaut.cornolti@epitech.eu>
** 
** Started on  Tue Dec  6 16:15:10 2016 Thibaut Cornolti
** Last update Sun Dec 11 21:17:29 2016 Thibaut Cornolti
*/

#include <ncurses.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my.h"

#ifndef SOKO_H_
# define SOKO_H_

typedef struct	s_pos
{
  int		x;
  int		y;
}		t_pos;

typedef struct	s_game
{
  char		**map;
  char		*filepath;
  t_pos		player;
  t_pos		*box;
  int		height;
  int		width;
}		t_game;

typedef struct	s_js_data
{
  int buttons;
  int x;
  int y;
}		t_js_data;


int	pos_is_box(t_game *, int, int);
int	move_box(t_game *, int, int, int);
int     get_box_at_pos(t_game *, int, int);
void	check_map(t_game *);
void	restart(t_game *);
void	stop_game();
void	start_game(t_game *);
int	start_js_game(t_game *);
int	check_game(t_game *);
int	move_player(t_game *, int);
void	my_soko_exit();
void	my_soko_exit_r();
void	load_file(char *, t_game *);
void	refresh_screen(t_game *);
void	fct_move_right(t_game *);
void	fct_move_left(t_game *);
void	fct_move_up(t_game *);
void	fct_move_down(t_game *);

#endif /* !SOKO_H_ */
