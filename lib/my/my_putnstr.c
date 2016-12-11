/*
** my_putnstr.c for my_putnstr in /home/thibrex/delivery/CPool_Day10/lib/my
** 
** Made by Thibaut Cornolti
** Login   <thibaut.cornolti@epitech.eu>
** 
** Started on  Sun Oct 16 00:16:02 2016 Thibaut Cornolti
** Last update Thu Nov  3 13:29:56 2016 Thibaut Cornolti
*/

#include <unistd.h>

int	my_putnstr(char *str, int i)
{
  int	j;

  j = 0;
  while (j < i)
    {
      write(1, &str[j], 1);
      j += 1;
    }
}
