/*
** choice_map_2.c for my_sokoban in /home/thibrex/Dropbox/delivery/PSU/PSU_2016_my_sokoban/bonus
** 
** Made by Thibaut Cornolti
** Login   <thibaut.cornolti@epitech.eu>
** 
** Started on  Tue Dec 13 19:08:39 2016 Thibaut Cornolti
** Last update Tue Dec 13 19:19:54 2016 Thibaut Cornolti
*/

#include <sys/types.h>
#include <dirent.h>
#include "soko.h"

void		choice_folder_2(t_game *g, char *path,
				t_dir *d, int *sel)
{
  struct stat	s;

  stat(cat_path(path, d->d_name), &s);
  *sel = 0;
  if (S_ISDIR(s.st_mode))
    choice_map(g, cat_path(path, d->d_name));
  else
    {
      g->filepath = cat_path(path, d->d_name);
      start_game(g);
    }
}
