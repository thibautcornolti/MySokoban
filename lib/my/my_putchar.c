/*
** my_putchar.c for my_putchar in /home/thibrex/delivery/CPool_Day06/tests
** 
** Made by Thibaut Cornolti
** Login   <thibaut.cornolti@epitech.eu@epitech.net>
** 
** Started on  Wed Oct 12 10:15:49 2016 Thibaut Cornolti
** Last update Thu Nov  3 13:24:17 2016 Thibaut Cornolti
*/

#include <unistd.h>

void	my_putchar(char c)
{
  write(1, &c, 1);
}
