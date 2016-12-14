/*
** utils.c for my_sokoban in /home/thibrex/delivery/PSU/PSU_2016_my_sokoban
** 
** Made by Thibaut Cornolti
** Login   <thibaut.cornolti@epitech.eu>
** 
** Started on  Tue Dec  6 16:34:08 2016 Thibaut Cornolti
** Last update Mon Dec 12 13:06:47 2016 Thibaut Cornolti
*/

#include "soko.h"

int		pos_is_box(t_game *g, int x, int y)
{
  int		i;

  i = -1;
  while ((g->box)[++i].x != -1)
    if (g->box[i].x == x && g->box[i].y == y)
      return (1);
  return (0);
}

int		get_box_at_pos(t_game *g, int x, int y)
{
  int		i;

  i = -1;
  while ((g->box)[++i].x != -1)
    if (g->box[i].x == x && g->box[i].y == y)
      return (i);
  return (-1);
}

void		my_soko_menu_r(t_game *g, char *msg)
{
  g->filepath = NULL;
  start_menu(g, msg, NULL);
}

void		my_soko_exit_r(char *str)
{
  endwin();
  my_puterror(str);
  exit(84);
}

void		my_soko_exit()
{
  endwin();
  my_puterror("Error.\n");
  exit(84);
}
