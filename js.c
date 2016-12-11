/*
** js.c for my_sokoban in /home/thibrex/Dropbox/delivery/PSU/PSU_2016_my_sokoban
** 
** Made by Thibaut Cornolti
** Login   <thibaut.cornolti@epitech.eu>
** 
** Started on  Sat Dec 10 02:51:03 2016 Thibaut Cornolti
** Last update Sat Dec 10 18:20:37 2016 Thibaut Cornolti
*/

#include "soko.h"

static int	init_js_game(int *cx, int *cy, t_js_data *js)
{
  int		fd;

  if ((fd = open("/dev/input/js0", O_RDONLY)) == -1)
    my_soko_exit_r("Erreur : Incompatibilité.");
  read(fd, js, sizeof(*js));
  *cx = js->x;
  *cy = js->y;
  timeout(100);
  return (fd);
}

static void	move_js(t_game *game, t_js_data *js, int cx, int cy)
{
  if (js->x <= cx - 10)
    fct_move_up(game);
  else if (js->x >= cx + 10)
    fct_move_down(game);
  else if (js->y >= cy + 10)
    fct_move_left(game);
  else if (js->y <= cy - 10)
    fct_move_right(game);
}

int		start_js_game(t_game *game)
{
  int		fd;
  int		cx;
  int		cy;
  int		ch;
  t_js_data	js;

  fd = init_js_game(&cx, &cy, &js);
  while (1)
    {
      ch = getch();
      read(fd, &js, sizeof(js));
      if (ch == 'j')
	return (cbreak());
      else if (move_player(game, ch));
      else if (ch == 'q')
	return (-42);
      else
	move_js(game, &js, cx, cy);
      refresh_screen(game);
      check_game(game);
    }
  return (0);
}
