/*
** my_getnbr_base.c for my_getnbr_base in /home/thibrex/delivery/CPool_Day06/tests
** 
** Made by Cornolti Thibaut
** Login   <thibrex@epitech.net>
** 
** Started on  Mon Oct 10 22:15:13 2016 Cornolti Thibaut
** Last update Sun Nov  6 22:20:34 2016 yann probst
*/

#include "my.h"

static int	contains_char(char c, char *str)
{
  int		i;

  i = 0;
  while (str[i] != 0)
    {
      if (str[i] == c)
	return (1);
      i += 1;
    }
  return (0);
}

static int	power(int i, int p)
{
  if (p == 0)
    return (1);
  if (p < 0)
    return (0);
  return (i * power(i, p - 1));
}

static int	my_getnbr_base_rec(char *str, char *base, int wh,  int len)
{
  int		nbr;
  int		i;

  i = 0;
  nbr = 0;
  if (*str == 0)
    return (0);
  while (base[i] != 0)
    {
      if (base[i] == *str)
	{
	  nbr = i * power(len, wh - 1);
	  return (nbr + my_getnbr_base_rec(str + 1, base, wh - 1, len));
	}
      else if (base[i + 1] == 0)
	return (0);
      i += 1;
    }
  return (nbr + my_getnbr_base_rec(str + 1, base, wh - 1, len));
}

int	my_getnbr_base(char *str, char *base)
{
  int	len;
  int	i;
  int	neg;

  neg = 1;
  i = 0;
  while (*str != 0 && (*str == '-' || *str == '+'))
    {
      if (*str == '-')
	neg *= -1;
      str += 1;
    }
  len = 0;
  while (base[len] != 0)
    len += 1;
  while (contains_char(str[i], base) == 1)
      i += 1;
  return (neg * my_getnbr_base_rec(str, base, i, len));
}
