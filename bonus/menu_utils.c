/*
** menu_utils.c for my_sokoban in /home/thibrex/Dropbox/delivery/PSU/PSU_2016_my_sokoban/bonus
** 
** Made by Thibaut Cornolti
** Login   <thibaut.cornolti@epitech.eu>
** 
** Started on  Tue Dec 13 18:16:35 2016 Thibaut Cornolti
** Last update Tue Dec 13 19:26:33 2016 Thibaut Cornolti
*/

#include "soko.h"

void		create_box(int pos_x, int pos_y, int x, int y)
{
  int		i;
  int		j;

  i = pos_x - 1;
  while (++i < pos_x + x)
    {
      j = pos_y - 1;
      mvprintw(i, pos_y, "|");
      mvprintw(i, pos_y + y - 1, "|");
      while (++j < pos_y + y)
	{
	  if (i == pos_x || i == pos_x + x - 1)
	    mvprintw(i, j, "-");
	}
    }
  mvprintw(pos_x, pos_y, "+");
  mvprintw(pos_x + x - 1, pos_y, "+");
  mvprintw(pos_x, pos_y + y - 1, "+");
  mvprintw(pos_x + x - 1, pos_y + y - 1, "+");
}
