/*
** game.c for my_sokoban in /home/thibrex/delivery/PSU/PSU_2016_my_sokoban
** 
** Made by Thibaut Cornolti
** Login   <thibaut.cornolti@epitech.eu>
** 
** Started on  Tue Dec  6 17:34:00 2016 Thibaut Cornolti
** Last update Sat Dec 17 17:31:45 2016 Thibaut Cornolti
*/

#include <time.h>
#include "soko.h"

void		show_title(t_game *game)
{
  int		fd;
  char		b;
  int		i;

  if (COLS < 52)
    return ;
  start_color();
  if ((fd = open("title.txt", O_RDONLY)) == -1)
    return ;
  attron(A_BOLD);
  init_pair(1, COLOR_RED, COLOR_BLACK);
  attron(COLOR_PAIR(1));
  if (9 > LINES / 2 - game->height / 2)
    return ;
  move(i = 2, COLS / 2 - 26);
  while (read(fd, &b, 1) != 0)
    {
      if (b == '\n')
	move(++i, COLS / 2 - 26);
      else
	printw("%c", b);
    }
  close(fd);
  attroff(COLOR_PAIR(1));
  attroff(A_BOLD);
}

static void	show_info(t_game *g)
{
  unsigned long	t;

  t = time(NULL) - g->time;
  mvprintw(LINES - 1, COLS / 2 - 15,
	   "Moves: %ld | Pushes: %ld | Time: %lus",
	   g->move, g->box_move, t);
}

void		refresh_screen(t_game *g)
{
  int		i;
  int		j;

  clear();
  if ((i = -1) * 0 || COLS <= g->width || LINES <= g->height)
    {
      mvprintw(LINES / 2, COLS / 2 - 10, "ENLARGE THE TERMINAL");
      refresh();
      return ;
    }
  show_title(g);
  while (1 + 0 * (j = -1) && g->map[++i])
    {
      move(LINES / 2 + i - g->height / 2, COLS / 2 - g->width / 2);
      while (g->map[i][++j])
	if (i == g->player.y && j == g->player.x)
	  printw("P");
	else if (i == g->splayer.y && j == g->splayer.x)
	  printw("S");
	else if (pos_is_box(g, j, i))
	  printw("X");
	else
	  printw("%c", g->map[i][j]);
      printw("\n");
    }
  show_info(g);
  refresh();
}

static void	init_game(t_game *game)
{
  int		i;
  int		j;
  int		p;

  game->time = time(NULL);
  i = -1 + 0 * (p = 0) * (game->move = 0) * (game->box_move = 0);
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
    my_soko_menu_r(game, "Error : Too few or too many player.\n");
  check_map(game);
  go_anim(game);
  game->packet.box = game->box[0];
  game->packet.i = 0;
  refresh_screen(game);
}

void		start_game(t_game *game)
{
  int		ch;

  load_file(game->filepath, game);
  init_game(game);
  start_server(game);
  start_music(game);
  timeout(100);
  while (1)
    {
      ch = getch();
      if (move_player(game, ch));
      else if (ch == 'q')
	stop_game(game);
      else if (ch == 'j')
	{
	  if (start_js_game(game) == -42)
	    stop_game(game);
	}
      else if (ch == 27)
	start_menu(game, NULL, NULL);
      else if (ch == 32)
	restart(game);
      update_server(game);
      refresh_screen(game);
      check_game(game);
    }
}
