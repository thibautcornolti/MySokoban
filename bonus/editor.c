/*
** editor.c for my_sokoban in /home/thibrex/Dropbox/delivery/PSU/PSU_2016_my_sokoban/bonus
** 
** Made by Thibaut Cornolti
** Login   <thibaut.cornolti@epitech.eu>
** 
** Started on  Mon Dec 12 14:35:41 2016 Thibaut Cornolti
** Last update Wed Dec 14 13:36:11 2016 Thibaut Cornolti
*/

#include "soko.h"

static void	start_editor_2(t_game *g, int ch)
{
  if (ch == KEY_RIGHT &&
      g->player.x < my_strlen(g->map[g->player.y]) - 1)
    g->player.x += 1;
  else if (ch == 'o' || ch == 'O')
    g->map[g->player.y][g->player.x] = 'O';
  else if (ch == 'x' || ch == 'X')
    g->map[g->player.y][g->player.x] = 'X';
  else if (ch == 'p' || ch == 'P')
    g->map[g->player.y][g->player.x] = 'P';
  else if (ch == '#' || ch == 'd')
    g->map[g->player.y][g->player.x] = '#';
  else if (ch == ' ')
    g->map[g->player.y][g->player.x] = ' ';
}

void		start_editor(t_game *g)
{
  int		ch;

  load_file(g->filepath, g);
  timeout(500);
  g->player.x = 0;
  g->player.y = 0;
  refresh_editor(g);
  while (1)
    {
      ch = getch();
      if (ch == 'q')
	stop_game();
      else if (ch == 27)
	start_menu(g, NULL, NULL);
      else if (ch == KEY_UP && g->player.y > 0)
	g->player.y -= 1;
      else if (ch == KEY_DOWN && g->player.y < g->height)
	g->player.y += 1;
      else if (ch == KEY_LEFT && g->player.x > 0)
	g->player.x -= 1;
      else
	start_editor_2(g, ch);
      refresh_editor(g);
    }
}
