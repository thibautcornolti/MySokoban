/*
** game.c for my_sokoban in /home/thibrex/delivery/PSU/PSU_2016_my_sokoban
** 
** Made by Thibaut Cornolti
** Login   <thibaut.cornolti@epitech.eu>
** 
** Started on  Tue Dec  6 17:34:00 2016 Thibaut Cornolti
** Last update Sun Dec 11 21:01:19 2016 Thibaut Cornolti
*/

#include "soko.h"

static void	show_title(t_game *game)
{
  int		fd;
  char		b;
  int		i;

  start_color();
  attron(A_BOLD);
  init_pair(1, COLOR_RED, COLOR_BLACK);
  attron(COLOR_PAIR(1));
  if ((fd = open("title.txt", O_RDONLY)) == -1)
    return ;
  i = 2;
  if (i + 7 > LINES / 2 - game->height / 2)
    return ;
  move(i, COLS / 2 - 26);
  while (read(fd, &b, 1) != 0)
    {
      if (b == '\n')
	move(++i, COLS / 2 - 26);
      else
	printw("%c", b);
    }
  attroff(COLOR_PAIR(1));
  attroff(A_BOLD);
}

void		refresh_screen(t_game *game)
{
  int		i;
  int		j;

  clear();
  i = -1;
  if (COLS <= game->width || LINES <= game->height)
    {
      mvprintw(LINES / 2, COLS / 2 - 10, "ENLARGE THE TERMINAL");
      refresh();
      return ;
    }
  show_title(game);
  while (1 + 0 * (j = -1) && game->map[++i])
    {
      move(LINES / 2 + i - game->height / 2, COLS / 2 - game->width / 2);
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
