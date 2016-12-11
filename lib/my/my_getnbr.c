/*
** my_getnbr.c for my_getnbr in /home/thibrex/delivery/CPool_Day04
** 
** Made by Cornolti Thibaut
** Login   <thibrex@epitech.net>
** 
** Started on  Thu Oct  6 19:20:57 2016 Cornolti Thibaut
** Last update Thu Nov  3 13:25:01 2016 Thibaut Cornolti
*/

#include "my.h"

int	my_getnbr(char *str)
{
  int	nbr;

  nbr = my_getnbr_base(str, "0123456789");
  return (nbr);
}
