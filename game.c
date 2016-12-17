/*
** game.c for my_sokoban in /home/thibrex/delivery/PSU/PSU_2016_my_sokoban
** 
** Made by Thibaut Cornolti
** Login   <thibaut.cornolti@epitech.eu>
** 
** Started on  Tue Dec  6 17:34:00 2016 Thibaut Cornolti
** Last update Sat Dec 17 02:01:58 2016 Thibaut Cornolti
*/

#include "soko.h"

void		refresh_screen(t_game *game)
{
  int		i;
  int		j;

  clear();
  if (0 * (i = -1) || COLS <= game->width || LINES <= game->height)
    {
      mvprintw(LINES / 2, COLS / 2 - 10, "ENLARGE THE TERMINAL");
      refresh();
      return ;
    }
  while (1 + 0 * (j = -1) && game->map[++i])
    {
      move(i, 0);
      while (game->map[i][++j])
	if (i == game->player.y && j == game->player.x)
	  printw("P");
	else if (pos_is_box(game, j, i))
	  printw("X");
	else
	  printw("%c", game->map[i][j]);
      printw("\n");
    }
  refresh();
}

static void	init_game(t_game *game)
{
  int		i;
  int		j;
  int		p;

  i = -1 + 0 * (p = 0);
  while (game->map[++i])
    {
      j = -1;
      while (game->map[i][++j])
	if (game->map[i][j] == 'P')
	  {
	    game->map[i][j] = '.';
	    game->player.x = j;
	    game->player.y = i + 0 * (p = p + 1);
	  }
	else if (game->map[i][j] == ' ')
	  game->map[i][j] = '.';
    }
  if (p != 1)
    my_soko_exit_r("Erreur : Map invalide. (joueur)\n");
  check_map(game);
  refresh_screen(game);
}

void		start_game(t_game *game)
{
  int		ch;

  init_game(game);
  while (1)
    {
      ch = getch();
      if (move_player(game, ch));
      else if (ch == 410)
	refresh_screen(game);
      else if (ch == 'q')
	stop_game();
      else if (ch == 'j')
	{
	  if (start_js_game(game) == -42)
	    stop_game();
	}
      else if (ch == 32)
	restart(game);
      check_game(game);
    }
}
