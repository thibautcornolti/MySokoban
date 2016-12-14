/*
** menu.c for my_sokoban in /home/thibrex/Dropbox/delivery/PSU/PSU_2016_my_sokoban/bonus
** 
** Made by Thibaut Cornolti
** Login   <thibaut.cornolti@epitech.eu>
** 
** Started on  Sun Dec 11 21:02:41 2016 Thibaut Cornolti
** Last update Wed Dec 14 14:42:13 2016 Thibaut Cornolti
*/

#include "soko.h"

static void	select_item(t_menu *m, int item)
{
  m->start = 0;
  m->editor = 0;
  m->exit = 0;
  if (item == 1)
    m->start = 1;
  else if (item == 2)
    m->editor = 1;
  else
    m->exit = 1;
}

static void	move_item(t_menu *m, int key)
{
  if (m->start && key == KEY_DOWN)
    select_item(m, 2);
  else if (m->editor && key == KEY_UP)
    select_item(m, 1);
  else if (m->editor && key == KEY_DOWN)
    select_item(m, 3);
  else if (m->exit && key == KEY_UP)
    select_item(m, 2);
}

static void	choice_item(t_game *g, t_menu *m)
{
  if (m->start)
    choice_map(g, NULL);
  if (m->editor)
    choice_editor(g, NULL);
  if (m->exit)
    stop_game();
}

void		refresh_menu(t_game *g, t_menu *m, char *msg)
{
  clear();
  show_title(g);
  attron(COLOR_PAIR(1));
  if (msg != NULL)
    mvprintw(LINES / 2 - 5, COLS / 2 - my_strlen(msg) / 2, "%s", msg);
  attroff(COLOR_PAIR(1));
  create_box(LINES / 2 - 3, COLS / 2 - 20, 13, 40);
  init_pair(2, COLOR_BLACK, COLOR_WHITE);
  if (m->start)
    attron(COLOR_PAIR(2));
  mvprintw(LINES / 2, COLS / 2 - 3, "Start!");
  attroff(COLOR_PAIR(2));
  if (m->editor)
    attron(COLOR_PAIR(2));
  mvprintw(LINES / 2 + 3, COLS / 2 - 3, "Editor");
  attroff(COLOR_PAIR(2));
  if (m->exit)
    attron(COLOR_PAIR(2));
  mvprintw(LINES / 2 + 6, COLS / 2 - 2, "Exit");
  attroff(COLOR_PAIR(2));
  refresh();
}

void		start_menu(t_game *g, char *msg, t_menu *menu)
{
  t_menu	m;
  int		ch;

  if (menu != NULL)
    m = *menu;
  else{
    m.start = 1;
    m.editor = 0;
    m.exit = 0;
  }
  refresh_menu(g, &m, msg);
  timeout(500);
  while (1)
    {
      ch = getch();
      if (ch == 'q')
	stop_game();
      if (ch == '\n' || ch == ' ')
	choice_item(g, &m);
      else
	move_item(&m, ch);
      if (ch != -1)
      	refresh_menu(g, &m, msg);
    }
}
