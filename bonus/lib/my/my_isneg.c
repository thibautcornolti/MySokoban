/*
** my_isneg.c for my_isneg in /home/thibrex/delivery/CPool_Day03
** 
** Made by Cornolti Thibaut
** Login   <thibrex@epitech.net>
** 
** Started on  Wed Oct  5 11:40:13 2016 Cornolti Thibaut
** Last update Thu Nov  3 13:26:08 2016 Thibaut Cornolti
*/

#include "my.h"

int	my_isneg(int n)
{
  if (n >= 0)
    my_putchar('P');
  else
    my_putchar('N');
  return (0);
}
