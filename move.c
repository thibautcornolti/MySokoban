/*
** move.c for my_sokoban in /home/thibrex/delivery/PSU/PSU_2016_my_sokoban
** 
** Made by Thibaut CornoltiP
** Login   <thibaut.cornolti@epitech.eu>
** 
** Started on  Wed Dec  7 11:24:11 2016 Thibaut Cornolti
** Last update Sat Dec 10 03:11:27 2016 Thibaut Cornolti
*/

#include "soko.h"

static void	init_move(int moves[4], void (*fct_moves[4])(t_game *))
{
  moves[0] = KEY_RIGHT;
  moves[1] = KEY_LEFT;
  moves[2] = KEY_UP;
  moves[3] = KEY_DOWN;
  fct_moves[0] = fct_move_right;
  fct_moves[1] = fct_move_left;
  fct_moves[2] = fct_move_up;
  fct_moves[3] = fct_move_down;
}

int		move_box(t_game *g, int x, int y, int move)
{
  if (!pos_is_box(g, x, y))
    return (1);
  if (move == 0 && g->map[y][x + 1] != '#' &&
      !pos_is_box(g, x + 1, y))
    return (1 + 0 * (g->box[get_box_at_pos(g, x, y)].x += 1));
  else if (move == 1 && g->map[y][x - 1] != '#' &&
	   !pos_is_box(g, x - 1, y))
    return (1 + 0 * (g->box[get_box_at_pos(g, x, y)].x -= 1));
  else if (move == 2 && g->map[y - 1][x] != '#' &&
	   !pos_is_box(g, x, y - 1))
    return (1 + 0 * (g->box[get_box_at_pos(g, x, y)].y -= 1));
  else if (move == 3 && g->map[y + 1][x] != '#' &&
	   !pos_is_box(g, x, y + 1))
    return (1 + 0 * (g->box[get_box_at_pos(g, x, y)].y += 1));
  return (0);
}

int		move_player(t_game *g, int move)
{
  int		i;
  int		moves[4];
  void		(*fct_moves[4])(t_game *);

  init_move(moves, fct_moves);
  i = 0;
  while (i < 4)
    {
      if (moves[i] == move)
	{
	  fct_moves[i](g);
	  refresh_screen(g);
	  return (1);
	}
      i += 1;
    }
  return (0);
}
