/*
** main.c for my_sokoban in /home/thibrex/delivery/PSU/PSU_2016_my_sokoban
** 
** Made by Thibaut Cornolti
** Login   <thibaut.cornolti@epitech.eu>
** 
** Started on  Tue Dec  6 10:05:11 2016 Thibaut Cornolti
** Last update Sat Dec 10 18:12:58 2016 Thibaut Cornolti
*/

#include "soko.h"

static void	my_initscr()
{
  initscr();
  noecho();
  cbreak();
  curs_set(0);
  keypad(stdscr, TRUE);
  nodelay(stdscr, TRUE);
}

void		stop_game()
{
  endwin();
  exit(0);
}

void		restart(t_game *g)
{
  load_file(g->filepath, g);
  start_game(g);
}

int		main(int ac, char **av)
{
  t_game	game;

  ac += 1;
  load_file(av[1], &game);
  game.filepath = av[1];
  my_initscr();
  start_game(&game);
  endwin();
  return (0);
}
