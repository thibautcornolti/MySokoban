/*
** my_fact_rec.c for my_fact_rec in /home/thibrex/delivery/CPool_Day05_no_repo/tests
** 
** Made by Cornolti Thibaut
** Login   <thibrex@epitech.net>
** 
** Started on  Fri Oct  7 11:15:39 2016 Cornolti Thibaut
** Last update Sun Nov  6 22:18:34 2016 yann probst
*/

int	my_fact_rec(int nb)
{
  if (nb < 0 || nb > 12)
    return (0);
  else if (nb == 0)
    return (1);
  else
    return (my_fact_rec(nb - 1) * nb);
}
