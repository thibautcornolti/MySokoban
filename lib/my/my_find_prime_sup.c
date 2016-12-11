/*
** my_find_prime_sup.c for my_find_prime_sup in /home/thibrex/delivery/CPool_Day05
** 
** Made by Cornolti Thibaut
** Login   <thibrex@epitech.net>
** 
** Started on  Fri Oct  7 19:38:43 2016 Cornolti Thibaut
** Last update Thu Nov  3 13:25:54 2016 Thibaut Cornolti
*/

#include "my.h"

int	my_find_prime_sup(int nb)
{
  if (my_is_prime(nb) == 1)
    return (nb);
  else
    {
      nb += 1;
      return (my_find_prime_sup(nb));
    }
}
