/*
** choice_map.c for my_sokoban in /home/thibrex/Dropbox/delivery/PSU/PSU_2016_my_sokoban/bonus
** 
** Made by Thibaut Cornolti
** Login   <thibaut.cornolti@epitech.eu>
** 
** Started on  Sun Dec 11 23:36:13 2016 Thibaut Cornolti
** Last update Fri Dec 16 23:31:19 2016 Thibaut Cornolti
*/

#include <sys/types.h>
#include <dirent.h>
#include "soko.h"

int		is_map(char *path, char *name)
{
  int		i;
  struct stat	s;

  i = my_strlen(name);
  stat(cat_path(path, name), &s);
  if (i <= 3)
    return (0);
  else if (my_strcmp(name + i - 3, ".sk") == 0 ||
	   S_ISDIR(s.st_mode))
    return (1);
  return (0);
}

void		refresh_folder(t_game *g, char *path, int *sel)
{
  DIR		*dir;
  struct dirent	*d;
  int		i;

  clear();
  show_title(g);
  init_pair(i = 2, COLOR_BLACK, COLOR_WHITE);
  if ((dir = opendir(path)) == NULL)
    start_menu(g, "Error. Try again!", NULL) ;
  if (*sel == 0)
    attron(COLOR_PAIR(2));
  mvprintw(LINES / 2, COLS / 2 - 1, "..");
  attroff(COLOR_PAIR(2));
  while ((d = readdir(dir)) != NULL)
    {
      if (*sel * 2 == i)
	attron(COLOR_PAIR(2));
      if (is_map(path, d->d_name))
	mvprintw(LINES / 2 + i, COLS / 2 - my_strlen(d->d_name) / 2,
		 d->d_name);
      attroff(COLOR_PAIR(2));
      i += 2 * is_map(path, d->d_name);
    }
  create_box(LINES / 2 - 3, COLS / 2 - 20, 5 + i, 40);
  refresh();
}

static void	choice_folder_ed_2(t_game *g, char *path, t_dir *d)
{
  struct stat	s;

  stat(cat_path(path, d->d_name), &s);
  if (S_ISDIR(s.st_mode))
    choice_editor(g, cat_path(path, d->d_name));
  else
    {
      g->filepath = cat_path(path, d->d_name);
      start_editor(g);
    }
}

static void	choice_folder(t_game *g, char *path, int *sel)
{
  DIR		*dir;
  t_dir		*d;
  int		i;

  i = 1;
  if ((dir = opendir(path)) == NULL)
    start_menu(g, "Error. Try again!", NULL) ;
  if (*sel == 0)
    choice_editor(g, cat_path(path, ".."));
  while ((d = readdir(dir)) != NULL)
    {
      if (!is_map(path, d->d_name))
	continue ;
      if (*sel == i)
	{
	  *sel = 0;
	  choice_folder_ed_2(g, path, d);
	  break;
	}
      i += is_map(path, d->d_name);
    }
}

void		choice_editor(t_game *g, char *p)
{
  int		sel;
  int		ch;
  char		*path;

  path = my_strdup(".");
  if (p != NULL)
    path = p;
  timeout(500);
  sel = 0;
  refresh_folder(g, path, &sel);
  while (1)
    {
      ch = getch();
      if (ch == 'q')
	stop_game(g);
      else if (ch == '\n' || ch == ' ')
	choice_folder(g, path, &sel);
      else if (ch == 27)
	start_menu(g, NULL, NULL);
      else
	move_folder(g, &sel, ch, path);
      if (ch != -1)
	refresh_folder(g, path, &sel);
    }
}
