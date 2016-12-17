/*
** check_game.c for my_sokoban in /home/thibrex/Dropbox/delivery/PSU/PSU_2016_my_sokoban
** 
** Made by Thibaut Cornolti
** Login   <thibaut.cornolti@epitech.eu>
** 
** Started on  Sun Dec 11 18:18:07 2016 Thibaut Cornolti
** Last update Sat Dec 17 02:25:45 2016 Thibaut Cornolti
*/

#include "soko.h"

int		check_game(t_game *g)
{
  int		i;
  int		j;
  int		ko;

  i = -1;
  ko = 0;
  while (g->map[++i])
    {
      j = -1;
      while (g->map[i][++j])
	if (g->map[i][j] == 'O' &&
	    !pos_is_box(g, j, i))
	  ko += 1;
    }
  if (ko == 0)
    stop_game_r(0);
  return (1);
}

