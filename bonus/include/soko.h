/*
** soko.h for my_sokoban in /home/thibrex/delivery/PSU/PSU_2016_my_sokoban
** 
** Made by Thibaut Cornolti
** Login   <thibaut.cornolti@epitech.eu>
** 
** Started on  Tue Dec  6 16:15:10 2016 Thibaut Cornolti
** Last update Wed Dec 14 14:48:11 2016 Thibaut Cornolti
*/

#ifndef SOKO_H_
# define SOKO_H_

#include <ncurses.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my.h"

typedef struct	dirent	t_dir;

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
  long		move;
  long		box_move;
  unsigned long	time;
}		t_game;

typedef struct	s_js_data
{
  int buttons;
  int x;
  int y;
}		t_js_data;

typedef struct	s_menu
{
  int		start;
  int		editor;
  int		exit;
}		t_menu;

int	pos_is_box(t_game *, int, int);
int	move_box(t_game *, int, int, int);
int     get_box_at_pos(t_game *, int, int);
void	check_map(t_game *);
void	restart(t_game *);
void	stop_game();
void	start_game(t_game *);
void	start_menu(t_game *, char *, t_menu *);
void	start_editor(t_game *);
int	start_js_game(t_game *);
int	check_game(t_game *);
void	show_title(t_game *);
void	move_folder(int *, int, char *);
void	refresh_folder(t_game *, char *, int *);
void	refresh_editor(t_game *);
int	is_map(char *, char *);
void	choice_map(t_game *, char *);
void	choice_editor(t_game *, char *);
void	choice_folder_2(t_game *, char *,
			t_dir *, int *);
char	*cat_path(char *, char *);
int	move_player(t_game *, int);
void	my_soko_menu_r();
void	my_soko_exit();
void	my_soko_exit_r();
void	load_file(char *, t_game *);
void	refresh_screen(t_game *);
void	refresh_menu(t_game *, t_menu *, char *);
void	create_box(int, int, int, int);
void	start_animation();
void	go_anim(t_game *g);
void	winner_anim(t_game *g);
void	looser_anim(t_game *g);
void	fct_move_right(t_game *);
void	fct_move_left(t_game *);
void	fct_move_up(t_game *);
void	fct_move_down(t_game *);

#endif /* !SOKO_H_ */
