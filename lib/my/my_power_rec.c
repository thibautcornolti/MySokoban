/*
** my_power_rec.c for my_power_rec in /home/thibrex/delivery/CPool_Day05_no_repo/tests
** 
** Made by Cornolti Thibaut
** Login   <thibrex@epitech.net>
** 
** Started on  Fri Oct  7 11:41:06 2016 Cornolti Thibaut
** Last update Sun Nov  6 22:22:26 2016 yann probst
*/

int	my_power_rec(int nb, int p)
{
  if (p < 0)
    return (0);
  else if (p == 0)
    return (1);
  else
    return (nb*my_power_rec(nb, p-1));
}
