/*
** my_showstr.c for my_showstr in /home/thibrex/delivery/CPool_Day06/tests
** 
** Made by Cornolti Thibaut
** Login   <thibrex@epitech.net>
** 
** Started on  Tue Oct 11 00:38:55 2016 Cornolti Thibaut
** Last update Thu Nov  3 13:29:43 2016 Thibaut Cornolti
*/

#include "my.h"

int	my_showstr(char *str)
{
  int	i;

  i = 0;
  while (str[i] != 0)
    {
      if (str[i] >= 32 && str[i] <= 126)
	  my_putchar(str[i]);
      else
	{
	  my_putchar('\\');
	  my_putnbr_base(str[i], "0123456789abcdef");
	}
      i += 1;
    }
  return (0);
}
