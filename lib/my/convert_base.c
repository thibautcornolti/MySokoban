/*
** convert_base.c for convert_base in /home/thibrex/delivery/CPool_Day08
** 
** Made by Thibaut Cornolti
** Login   <thibaut.cornolti@epitech.eu@epitech.net>
** 
** Started on  Wed Oct 12 16:06:56 2016 Thibaut Cornolti
** Last update Fri Nov 25 14:55:43 2016 Thibaut Cornolti
*/

#include <stdlib.h>
#include "my.h"

static int	my_convertnbr_base_rec(long nbr, char *base,
				       int len, char *str)
{
  int		i;
  char		temp[2];

  i = nbr / len;
  temp[1] = 0;
  if (i >= len || i <= -len)
    my_convertnbr_base_rec(i, base, len, str);
  else
    {
      temp[0] = base[i];
      my_strcat(str, temp);
    }
  temp[0] = base[nbr % len];
  my_strcat(str, temp);
}

char	*convert_base(char *nbr, char *base_from, char *base_to)
{
  long	inbr;
  char	*str;

  if ((str = malloc(sizeof(char) * 65)) == NULL)
    exit(my_puterror("error") + 84);
  inbr = my_getnbr_base(nbr, base_from);
  if (inbr < 0)
    {
      my_strcat(str, "-");
      inbr = -inbr;
    }
  my_convertnbr_base_rec(inbr, base_to, my_strlen(base_to), str);
  return (str);
}

