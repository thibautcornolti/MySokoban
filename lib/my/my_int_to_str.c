/*
** my_int_to_str.c for my_int_to_str in /home/thibrex/delivery/libgen/my
** 
** Made by Thibaut Cornolti
** Login   <thibaut.cornolti@epitech.eu>
** 
** Started on  Tue Oct 25 11:40:26 2016 Thibaut Cornolti
** Last update Sun Dec  4 21:58:32 2016 Thibaut Cornolti
*/

#include <stdlib.h>
#include "my.h"

char	*my_int_to_str(int nbr, char *result)
{
  int	i;
  int	nbrr;

  nbrr = nbr;
  i = 0;
  if (nbr < 0)
    nbr *= -1;
  while (nbr != 0)
    {
      result[i++] = nbr % 10 + '0';
      nbr /= 10;
    }
  if (nbrr < 0)
    result[i++] = '-';
  result[i] = 0;
  if (nbrr == 0)
    {
      result[0] = '0';
      result[1] = 0;
    }
  return (my_revstr(result));
}
