/*
** animation.c for my_sokoban in /home/thibrex/Dropbox/delivery/PSU/PSU_2016_my_sokoban/bonus
** 
** Made by Thibaut Cornolti
** Login   <thibaut.cornolti@epitech.eu>
** 
** Started on  Wed Dec 14 14:20:30 2016 Thibaut Cornolti
** Last update Sat Dec 17 00:34:10 2016 Thibaut Cornolti
*/

#include "soko.h"

static void	show_ti(int x)
{
  int		fd;
  char		b;
  int		i;

  clear();
  if ((fd = open("title.txt", O_RDONLY)) == -1)
    return ;
  i = x;
  move(i, COLS / 2 - 26);
  while (read(fd, &b, 1) != 0)
    {
      if (b == '\n')
	move(++i, COLS / 2 - 26);
      else
	printw("%c", b);
    }
  refresh();
}

void		looser_anim(t_game *g)
{
  int		fd;
  char		b;
  int		i;

  FMOD_System_PlaySound(g->f_sys, g->f_lose, NULL, 0, NULL);
  FMOD_System_Update(g->f_sys);
  if (COLS < 81)
    return ;
  clear();
  show_title(g);
  attron(A_BOLD);
  attron(COLOR_PAIR(1));
  if ((fd = open("looser.txt", O_RDONLY)) == -1)
    return ;
  i = LINES / 2 - 3;
  move(i, COLS / 2 - 39);
  while (read(fd, &b, 1) != 0)
    if (b == '\n')
      move(++i, COLS / 2 - 39);
    else
      printw("%c", b);
  attroff(COLOR_PAIR(1));
  attroff(A_BOLD);
  refresh();
  usleep(4000000);
}

void		winner_anim(t_game *g)
{
  int		fd;
  char		b;
  int		i;

  FMOD_System_PlaySound(g->f_sys, g->f_win, NULL, 0, NULL);
  FMOD_System_Update(g->f_sys);
  if (COLS < 63)
    return ;
  clear();
  show_title(g);
  attron(A_BOLD);
  init_pair(4, COLOR_GREEN, COLOR_BLACK);
  attron(COLOR_PAIR(4));
  if ((fd = open("winner.txt", O_RDONLY)) == -1)
    return ;
  move((i = LINES / 2 - 3), COLS / 2 - 30);
  while (read(fd, &b, 1) != 0)
    if (b == '\n')
      move(++i, COLS / 2 - 30);
    else
      printw("%c", b);
  attroff(COLOR_PAIR(4));
  attroff(A_BOLD);
  refresh();
  usleep(6000000);
}

void		go_anim(t_game *g)
{
  int		fd;
  char		b;
  int		i;

  if (COLS < 25)
    return ;
  clear();
  show_title(g);
  attron(A_BOLD);
  init_pair(4, COLOR_GREEN, COLOR_BLACK);
  attron(COLOR_PAIR(4));
  if ((fd = open("go.txt", O_RDONLY)) == -1)
    return ;
  i = LINES / 2 - 3;
  move(i, COLS / 2 - 12);
  while (read(fd, &b, 1) != 0)
    if (b == '\n')
      move(++i, COLS / 2 - 12);
    else
      printw("%c", b);
  attroff(COLOR_PAIR(4));
  attroff(A_BOLD);
  refresh();
  usleep(1000000);
}

void		start_animation()
{
  int		i;

  i = LINES - 5;
  if (COLS < 53)
    return ;
  start_color();
  attron(A_BOLD);
  init_pair(1, COLOR_RED, COLOR_BLACK);
  attron(COLOR_PAIR(1));
  while (i > 2)
    {
      show_ti(i);
      usleep(10000);
      i -= 1;
    }
  attroff(COLOR_PAIR(1));
  attroff(A_BOLD);
}
