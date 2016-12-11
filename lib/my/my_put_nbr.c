/*
** my_put_nbr.c for my_put_nbr in /home/thibrex/delivery/CPool_Day03
** 
** Made by Thibaut Cornolti
** Login   <thibaut.cornolti@epitech.eu>
** 
** Started on  Wed Oct  5 15:13:12 2016 Cornolti Thibaut
** Last update Thu Nov  3 13:24:37 2016 Thibaut Cornolti
*/

#include "my.h"

int	my_put_nbr(int nb)
{
  long	lnb;

  lnb = nb;
  if (lnb < 0)
    {
      my_putchar('-');
      lnb = -lnb;
    }
  if (lnb < 10)
    my_putchar(lnb + 48);
  else
    {
      my_put_nbr(lnb / 10);
      my_putchar(lnb % 10 + 48);
    }
  return (0);
}
