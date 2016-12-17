/*
** utils2.c for my_sokoban in /home/thibrex/Dropbox/delivery/PSU/PSU_2016_my_sokoban/bonus
** 
** Made by Thibaut Cornolti
** Login   <thibaut.cornolti@epitech.eu>
** 
** Started on  Sat Dec 17 16:07:22 2016 Thibaut Cornolti
** Last update Sat Dec 17 16:09:48 2016 Thibaut Cornolti
*/

#include "soko.h"

int		get_box_len(t_game *g)
{
  int           i;

  i = -1;
  while ((g->box)[++i].x != -1);
  return (i);
}
