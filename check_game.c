/*
** check_game.c for my_sokoban in /home/thibrex/Dropbox/delivery/PSU/PSU_2016_my_sokoban
** 
** Made by Thibaut Cornolti
** Login   <thibaut.cornolti@epitech.eu>
** 
** Started on  Sun Dec 11 18:18:07 2016 Thibaut Cornolti
** Last update Mon Dec 12 14:01:06 2016 Thibaut Cornolti
*/

#include "soko.h"

static int	check_box(t_game *g, int x, int y)
{
  int		mv;

  mv = 0;
  if ((g->map[y + 1][x] == '#' || pos_is_box(g, x, y + 1)) &&
      (g->map[y][x + 1] == '#' || pos_is_box(g, x + 1, y)))
    mv += 1;
  if ((g->map[y - 1][x] == '#' || pos_is_box(g, x, y - 1)) &&
      (g->map[y][x + 1] == '#' || pos_is_box(g, x + 1, y)))
    mv += 1;
  if ((g->map[y + 1][x] == '#' || pos_is_box(g, x, y + 1)) &&
      (g->map[y][x - 1] == '#' || pos_is_box(g, x - 1, y)))
    mv += 1;
  if ((g->map[y - 1][x] == '#' || pos_is_box(g, x, y - 1)) &&
      (g->map[y][x - 1] == '#' || pos_is_box(g, x - 1, y)))
    mv += 1;
  if (mv >= 1)
    return (1);
  return (0);
}

int		check_game(t_game *g)
{
  int		i;
  int		j;
  int		kobox;
  int		ko;
  int		box;

  i = -1;
  ko = 0;
  kobox = 0;
  box = 0;
  while (g->map[++i])
    {
      j = -1;
      while (g->map[i][++j])
	if (g->map[i][j] == 'O' &&
	    !pos_is_box(g, j, i))
	  ko += 1;
	else if (pos_is_box(g, j, i))
	  kobox += check_box(g, j, i) + 0 * (box += 1);
    }
  if (ko == 0 || kobox == box)
    stop_game();
  return (1);
}

