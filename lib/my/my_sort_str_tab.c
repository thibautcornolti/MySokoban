/*
** my_sort_str_tab.c for lib in /home/thibrex/delivery/PSU/PSU_2016_my_ls/lib/my
** 
** Made by Thibaut Cornolti
** Login   <thibaut.cornolti@epitech.eu>
** 
** Started on  Wed Nov 23 16:58:55 2016 Thibaut Cornolti
** Last update Wed Nov 23 17:19:24 2016 Thibaut Cornolti
*/

#include "my.h"

void	my_sort_str_tab(char **tab)
{
  char	*temp;
  int	i;
  int	j;

  i = 0;
  while (tab[i])
    {
      j = i + 1;
      while (tab[j])
	{
	  if (my_strcmp(tab[j], tab[i]) < 0)
	    {
	      temp = my_strdup(tab[i]);
	      tab[i] = tab[j];
	      tab[j] = temp;
	    }
	  j += 1;
	}
      i += 1;
    }
}
