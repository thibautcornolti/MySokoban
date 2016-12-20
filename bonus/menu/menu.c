/*
** menu.c for my_sokoban in /home/thibrex/Dropbox/delivery/PSU/PSU_2016_my_sokoban/bonus
** 
** Made by Thibaut Cornolti
** Login   <thibaut.cornolti@epitech.eu>
** 
** Started on  Sun Dec 11 21:02:41 2016 Thibaut Cornolti
** Last update Mon Dec 19 00:17:57 2016 Thibaut Cornolti
*/

#include "soko.h"

static void	select_item(t_game *g, t_menu *m, int item)
{
  m->start = 0;
  m->connect = 0;
  m->editor = 0;
  m->exit = 0;
  FMOD_System_PlaySound(g->f_sys, g->f_check, NULL, 0, NULL);
  FMOD_System_Update(g->f_sys);
  if (item == 1)
    m->start = 1;
  else if (item == 2)
    m->connect = 1;
  else if (item == 3)
    m->editor = 1;
  else
    m->exit = 1;
}

static void	move_item(t_game *g, t_menu *m, int key)
{
  if (m->start && key == KEY_DOWN)
    select_item(g, m, 2);
  else if (m->connect && key == KEY_UP)
    select_item(g, m, 1);
  else if (m->connect && key == KEY_DOWN)
    select_item(g, m, 3);
  else if (m->editor && key == KEY_UP)
    select_item(g, m, 2);
  else if (m->editor && key == KEY_DOWN)
    select_item(g, m, 4);
  else if (m->exit && key == KEY_UP)
    select_item(g, m, 3);
}

static void	choice_item(t_game *g, t_menu *m)
{
  if (m->start)
    choice_map(g, NULL);
  if (m->editor)
    choice_editor(g, NULL);
  if (m->connect)
    choice_connect(g, NULL);
  if (m->exit)
    stop_game(g);
}

void		refresh_menu(t_game *g, t_menu *m, char *msg)
{
  clear();
  show_title(g);
  attron(COLOR_PAIR(1));
  if (msg != NULL)
    mvprintw(LINES / 2 - 5, COLS / 2 - my_strlen(msg) / 2, "%s", msg);
  attroff(COLOR_PAIR(1));
  create_box(LINES / 2 - 3, COLS / 2 - 20, 16, 40);
  init_pair(2, COLOR_BLACK, COLOR_WHITE);
  if (m->start)
    attron(COLOR_PAIR(2));
  mvprintw(LINES / 2, COLS / 2 - 3, "Start!");
  attroff(COLOR_PAIR(2));
  if (m->connect)
    attron(COLOR_PAIR(2));
  mvprintw(LINES / 2 + 3, COLS / 2 - 4, "Connect!");
  attroff(COLOR_PAIR(2));
  if (m->editor)
    attron(COLOR_PAIR(2));
  mvprintw(LINES / 2 + 6, COLS / 2 - 3, "Editor");
  attroff(COLOR_PAIR(2));
  if (m->exit)
    attron(COLOR_PAIR(2));
  mvprintw(LINES / 2 + 9, COLS / 2 - 2, "Exit");
  attroff(COLOR_PAIR(2));
  refresh();
}

void		start_menu(t_game *g, char *msg, t_menu *menu)
{
  t_menu	m;
  int		ch;

  stop_music(g);
  start_music_menu(g);
  init_var(g, &m);
  if (menu != NULL)
    m = *menu;
  refresh_menu(g, &m, msg);
  timeout(500);
  while ((ch = getch()))
    {
      if (ch == 'q')
	stop_game(g);
      else if (ch == '\n' || ch == ' ')
	choice_item(g, &m);
      else
	move_item(g, &m, ch);
      if (ch != -1)
      	refresh_menu(g, &m, msg);
    }
}
