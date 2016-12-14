/*
** my_strlen.c for my_strlen in //home/thibrex/delivery/CPool_Day04
** 
** Made by Cornolti Thibaut
** Login   <thibrex@epitech.net>
** 
** Started on  Thu Oct  6 10:42:10 2016 Cornolti Thibaut
** Last update Sun Dec  4 21:53:42 2016 Thibaut Cornolti
*/

#include <stdlib.h>

int	my_strlen(char *str)
{
  int	lenght;

  if (str == NULL)
    return (0);
  lenght = 0;
  while (*str != 0)
    {
      str += 1;
      lenght += 1;
    }
  return (lenght);
}
