/*
** editor_utils.c for my_sokoban in /home/thibrex/Dropbox/delivery/PSU/PSU_2016_my_sokoban/bonus
** 
** Made by Thibaut Cornolti
** Login   <thibaut.cornolti@epitech.eu>
** 
** Started on  Wed Dec 14 13:29:25 2016 Thibaut Cornolti
** Last update Wed Dec 14 13:33:18 2016 Thibaut Cornolti
*/

#include "soko.h"

static void	save_file(t_game *g)
{
  int		fd;
  int		j;
  int		i;

  fd = open(g->filepath, O_RDWR);
  if (fd == -1)
    return ;
  i = -1;
  while (g->map[++i])
    {
      j = -1;
      while (g->map[i][++j])
	{
	  write(fd, &(g->map[i][j]), 1);
	}
      write(fd, "\n", 1);
    }
  close(fd);
}

static int	refresh_editor_2(t_game *g)
{
  if (COLS <= g->width + 3 || LINES <= g->height + 3)
    {
      mvprintw(LINES / 2, COLS / 2 - 10, "ENLARGE THE TERMINAL");
      refresh();
      return (1);
    }
  return (0);
}

void		refresh_editor(t_game *g)
{
  int		i;
  int		j;

  i = -1;
  clear();
  show_title(g);
  if (refresh_editor_2(g))
    return ;
  while (1 + 0 * (j = -1) && g->map[++i])
    while (g->map[i][++j])
      {
	init_pair(3, COLOR_BLACK, COLOR_WHITE);
	if (j == g->player.x && i == g->player.y)
	  attron(COLOR_PAIR(3));
	mvprintw(LINES / 2 + i - g->height / 2,
		 COLS / 2 - g->width / 2 + j, "%c\n", g->map[i][j]);
	attroff(COLOR_PAIR(3));
      }
  create_box(LINES / 2 - g->height / 2 - 3,
	     COLS / 2 - g->width / 2 - 3,
	     g->height + 6, g->width + 6);
  save_file(g);
  refresh();
}
