/*
** my_strstr.c for my_strstr in /home/thibrex/delivery/CPool_Day06/tests
** 
** Made by Cornolti Thibaut
** Login   <thibrex@epitech.net>
** 
** Started on  Mon Oct 10 10:47:27 2016 Cornolti Thibaut
** Last update Sun Nov  6 21:36:12 2016 Thibaut Cornolti
*/

#include <stdlib.h>

char	*my_strstr(char *str, char *to_find)
{
  int	pos;
  int	l;
  int	i;

  l = 0;
  if (to_find[0] == 0)
    return (str);
  while (str[l] != 0)
    {
      if (str[l] == to_find[0])
	{
	  pos = l;
	  i = 0;
	  while (str[l] == to_find[i] && str[l] != 0)
	    {
	      i += 1;
	      if (to_find[i] == 0)
		return (str + pos);
	      l += 1;
	    }
	  l = pos;
	}
      l += 1;
    }
  return (NULL);
}
