/*
** fct.c for my_sokoban in /home/thibrex/delivery/PSU/PSU_2016_my_sokoban
** 
** Made by Thibaut Cornolti
** Login   <thibaut.cornolti@epitech.eu>
** 
** Started on  Wed Dec  7 11:30:10 2016 Thibaut Cornolti
** Last update Sat Dec 17 00:20:49 2016 Thibaut Cornolti
*/

#include "soko.h"

void	fct_move_right(t_game *g)
{
  int	*x;
  int	*y;

  x = &(g->player.x);
  y = &(g->player.y);
  if (g->map[*y][*x + 1] != '#' && move_box(g, *x + 1, *y, 0))
    {
      FMOD_System_PlaySound(g->f_sys, g->f_move, NULL, 0, NULL);
      FMOD_System_Update(g->f_sys);
      *x += 1;
      g->move += 1;
    }
}

void	fct_move_left(t_game *g)
{
  int	*x;
  int	*y;

  x = &(g->player.x);
  y = &(g->player.y);
  if (g->map[*y][*x - 1] != '#' && move_box(g, *x - 1, *y, 1))
    {
      FMOD_System_PlaySound(g->f_sys, g->f_move, NULL, 0, NULL);
      FMOD_System_Update(g->f_sys);
      *x -= 1;
      g->move += 1;
    }
}

void	fct_move_up(t_game *g)
{
  int	*x;
  int	*y;

  x = &(g->player.x);
  y = &(g->player.y);
  if (g->map[*y - 1][*x] != '#' && move_box(g, *x, *y - 1, 2))
    {
      FMOD_System_PlaySound(g->f_sys, g->f_move, NULL, 0, NULL);
      FMOD_System_Update(g->f_sys);
      *y -= 1;
      g->move += 1;
    }
}

void	fct_move_down(t_game *g)
{
  int	*x;
  int	*y;

  x = &(g->player.x);
  y = &(g->player.y);
  if (g->map[*y + 1][*x] != '#' && move_box(g, *x, *y + 1, 3))
    {
      FMOD_System_PlaySound(g->f_sys, g->f_move, NULL, 0, NULL);
      FMOD_System_Update(g->f_sys);
      *y += 1;
      g->move += 1;
    }
}
