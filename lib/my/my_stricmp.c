/*
** my_stricmp.c for my_stricmp in /home/thibrex/delivery/CPool_Day06/tests
** 
** Made by Cornolti Thibaut
** Login   <thibrex@epitech.net>
** 
** Started on  Mon Oct 10 11:28:45 2016 Cornolti Thibaut
** Last update Fri Dec  2 09:11:09 2016 Thibaut Cornolti
*/

#include "my.h"

int	my_stricmp(char *s1, char *s2)
{
  int	i;
  char	*tmp1;
  char	*tmp2;

  tmp1 = my_strdup(s1);
  tmp2 = my_strdup(s2);
  i = -1;
  while (tmp1[++i])
    if (tmp1[i] >= 'A' && tmp1[i] <= 'Z')
      tmp1[i] += 32;
  i = -1;
  while (tmp2[++i])
    if (tmp2[i] >= 'A' && tmp2[i] <= 'Z')
      tmp2[i] += 32;
  i = 0;
  while (tmp1[i] != 0 || tmp2[i] != 0)
    {
      if (s1[i] != s2[i])
	return ((tmp1[i] - tmp2[i] < 0) ? -1 : 1);
      i += 1;
    }
  return (0);
}
