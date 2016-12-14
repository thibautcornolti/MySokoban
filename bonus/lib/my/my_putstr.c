/*
** my_putstr.c for my_putstr in //home/thibrex/delivery/CPool_Day04
** 
** Made by Cornolti Thibaut
** Login   <thibrex@epitech.net>
** 
** Started on  Thu Oct  6 10:16:08 2016 Cornolti Thibaut
** Last update Thu Nov  3 13:30:16 2016 Thibaut Cornolti
*/

#include "my.h"

int	my_putstr(char *str)
{
  while (*str != 0)
    {
      my_putchar(*str);
      str += 1;
    }
  return (0);
}
