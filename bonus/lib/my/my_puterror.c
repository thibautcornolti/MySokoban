/*
** my_puterror.c for my_puterror in //home/thibrex/delivery/CPool_Day04
** 
** Made by Cornolti Thibaut
** Login   <thibrex@epitech.net>
** 
** Started on  Sat Oct 15 16:29:08 2016 Cornolti Thibaut
** Last update Thu Nov  3 13:43:02 2016 Thibaut Cornolti
*/

#include <unistd.h>
#include "my.h"

int	my_puterror(char *str)
{
  write(2, str, my_strlen(str));
  return (0);
}
