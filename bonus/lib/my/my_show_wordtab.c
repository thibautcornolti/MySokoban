/*
** my_show_wordtab.c for my_show_wordtab in /home/thibrex/delivery/CPool_Day08
** 
** Made by Thibaut Cornolti
** Login   <thibaut.cornolti@epitech.eu@epitech.net>
** 
** Started on  Wed Oct 12 10:55:07 2016 Thibaut Cornolti
** Last update Thu Nov  3 13:27:07 2016 Thibaut Cornolti
*/

#include "my.h"

int	my_show_wordtab(char **tab)
{
  if (*tab == 0)
    return (0);
  if (**tab != 0)
    my_putstr(*tab);
  my_putchar('\n');
  return (my_show_wordtab(tab + 1));
}
