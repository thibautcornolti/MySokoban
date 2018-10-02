/*
** check.c for my_sokoban in /home/thibrex/delivery/PSU/PSU_2016_my_sokoban
** 
** Made by Thibaut Cornolti
** Login   <thibaut.cornolti@epitech.eu>
** 
** Started on  Wed Dec  7 15:45:38 2016 Thibaut Cornolti
** Last update Sun Dec 11 23:29:47 2016 Thibaut Cornolti
*/

#include "soko.h"

static void	rec_check_map(t_game *g, int x, int y)
{
  if (x - 1 < 0 || y - 1 < 0 || g->map[y + 1] == NULL ||
      g->map[y][x + 1] == 0 || g->map[y][x + 1] == '\n')
    my_soko_exit_r("Erreur : Map invalide (bordure).\n");
  if (g->map[y][x] == '#')
    return ;
  g->map[y][x] = ' ';
  if (g->map[y][x + 1] == '.')
    rec_check_map(g, x + 1, y);
  if (g->map[y + 1][x] == '.')
    rec_check_map(g, x, y + 1);
  if (g->map[y][x - 1] == '.')
    rec_check_map(g, x - 1, y);
  if (g->map[y - 1][x] == '.')
    rec_check_map(g, x, y - 1);
}

static void	repair_dot(t_game *g)
{
  int		i;
  int		j;

  i = -1;
  while (g->map[++i])
    {
      j = -1;
      while (g->map[i][++j])
	if (g->map[i][j] == '.')
	  g->map[i][j] = ' ';
    }
}

static void	init_box(t_game *g)
{
  int		i;
  int		j;
  int		k;

  i = (k = -1);
  if ((g->box = malloc(sizeof(t_pos) * g->width * g->height)) == NULL)
    my_soko_exit_r("Erreur : Mémoire insuffisante.\n");
  while (g->map[++i])
    {
      j = -1;
      while (g->map[i][++j])
	if (g->map[i][j] == 'X')
	  {
	    g->box[++k].x = j;
	    g->box[k].y = i;
	    g->box[k + 1].x = -1;
	    g->map[i][j] = '.';
	  }
    }
}

void		check_map(t_game *g)
{
  init_box(g);
  if (g->player.x <= 0 || g->player.y <= 0)
    my_soko_exit_r("Erreur : Map invalide. (joueur)");
  rec_check_map(g, g->player.x, g->player.y);
  repair_dot(g);
}
