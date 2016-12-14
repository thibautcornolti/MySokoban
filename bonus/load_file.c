/*
** load_file.c for my_sokoban in /home/thibrex/delivery/PSU/PSU_2016_my_sokoban
** 
** Made by Thibaut Cornolti
** Login   <thibaut.cornolti@epitech.eu>
** 
** Started on  Tue Dec  6 16:14:40 2016 Thibaut Cornolti
** Last update Wed Dec 14 14:09:38 2016 Thibaut Cornolti
*/

#include "soko.h"

static int	get_file_size(char *path, t_game *g)
{
  int		size;
  int		fd;
  char		b;

  size = 0;
  if ((fd = open(path, O_RDONLY)) == -1)
    my_soko_menu_r(g, "Error: File not found.\n");
  while (read(fd, &b, 1) != 0)
    size += 1;
  close(fd);
  return (size + 12);
}

static void	fill_map(t_game *g, int fd_file)
{
  int		i;
  int		j;
  int		max_width;
  char		b;

  i = 0;
  j = 0;
  max_width = 0;
  while (read(fd_file, &b, 1) != 0)
    if (b == '\n')
      {
	g->map[i][j] = 0;
	max_width = (j > max_width) ? j : max_width;
	i += 1 + (j = 0);
      }
    else
      {
	g->map[i][j] = b;
	j += 1;
      }
  g->map[i][j] = 0;
  g->map[i + 1] = 0;
  g->height = i;
  g->width = max_width;
}

void		load_file(char *path, t_game *g)
{
  int		fd;
  int		size;
  int		i;

  i = -1;
  if ((fd = open(path, O_RDONLY)) == -1)
    my_soko_menu_r(g, "Error: File not found.\n");
  size = get_file_size(path, g);
  if ((g->map = malloc(sizeof(char *) * size)) == NULL)
    my_soko_menu_r(g, "Error: Insufficient memory.\n");
  while (++i < size)
    if ((g->map[i] = malloc(sizeof(char) * size)) == NULL)
      my_soko_exit();
  fill_map(g, fd);
  close(fd);
  if (g->width <= 1 || g->height <= 1)
    my_soko_menu_r(g, "Error: Unrecognized file.\n");
}
