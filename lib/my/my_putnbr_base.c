/*
** my_putnbr_base.c for my_putnbr_base in /home/thibrex/delivery/CPool_Day06/tests
** 
** Made by Cornolti Thibaut
** Login   <thibrex@epitech.net>
** 
** Started on  Mon Oct 10 16:57:57 2016 Cornolti Thibaut
** Last update Sun Nov  6 22:23:28 2016 yann probst
*/

#include "my.h"

static int	my_putnbr_base_rec(long nbr, char *base, int len)
{
  int		i;

  i = nbr / len;
  if (i > len)
    my_putnbr_base_rec(i, base, len);
  else
    my_putchar(base[i]);
  my_putchar(base[nbr % len]);
}

int		my_putnbr_base(int nbr, char *base)
{
  int		i;
  long		lnbr;

  i = 0;
  lnbr = nbr;
  while (base[i])
      i += 1;
  if (nbr >= 0)
    my_putnbr_base_rec(lnbr, base, i);
  else
    {
      my_putchar('-');
      my_putnbr_base_rec(-lnbr, base, i);
    }
}
