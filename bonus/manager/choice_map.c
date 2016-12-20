/*
** choice_map.c for my_sokoban in /home/thibrex/Dropbox/delivery/PSU/PSU_2016_my_sokoban/bonus
** 
** Made by Thibaut Cornolti
** Login   <thibaut.cornolti@epitech.eu>
** 
** Started on  Sun Dec 11 23:36:13 2016 Thibaut Cornolti
** Last update Sat Dec 17 00:20:36 2016 Thibaut Cornolti
*/

#include <sys/types.h>
#include <dirent.h>
#include "soko.h"

char		*cat_path(char *path, char *name)
{
  char		*result;
  int		i;
  int		j;

  if (path == NULL)
    return (name);
  result = malloc(sizeof(char) *
		  (my_strlen(path) + my_strlen(name) + 2));
  if (result == NULL)
    return (NULL);
  i = -1;
  j = -1;
  while (path[++i])
    result[++j] = path[i];
  i = -1;
  if (result[j] != '/')
    result[++j] = '/';
  while (name[++i])
    result[++j] = name[i];
  result[++j] = 0;
  return (result);
}

static int	folder_len(char *path)
{
  DIR		*dir;
  int		len;
  t_dir		*d;

  if ((dir = opendir(path)) == NULL)
    return (0);
  len = 0;
  while ((d = readdir(dir)) != NULL)
    len += is_map(path, d->d_name);
  return (len);
}

static void	choice_folder(t_game *g, char *path, int *sel)
{
  DIR		*dir;
  struct dirent	*d;
  int		i;

  i = 1;
  if ((dir = opendir(path)) == NULL)
    start_menu(g, "Error. Try again!", NULL) ;
  if (*sel == 0)
    choice_map(g, cat_path(path, ".."));
  while ((d = readdir(dir)) != NULL)
    {
      if (!is_map(path, d->d_name))
	continue ;
      if (*sel == i)
	{
	  choice_folder_2(g, path, d, sel);
	  break;
	}
      i += is_map(path, d->d_name);
    }
}

void		move_folder(t_game *g, int *sel, int ch, char *path)
{
  if (ch == KEY_UP && *sel > 0)
    {
      FMOD_System_PlaySound(g->f_sys, g->f_check, NULL, 0, NULL);
      FMOD_System_Update(g->f_sys);
      *sel -= 1;
    }
  else if (ch == KEY_DOWN && *sel < folder_len(path))
    {
      FMOD_System_PlaySound(g->f_sys, g->f_check, NULL, 0, NULL);
      FMOD_System_Update(g->f_sys);
      *sel += 1;
    }
}

void		choice_map(t_game *g, char *p)
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
