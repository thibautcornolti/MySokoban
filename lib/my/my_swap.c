/*
** my_swap.c for my_swap in //home/thibrex/delivery/CPool_Day04
** 
** Made by Cornolti Thibaut
** Login   <thibrex@epitech.net>
** 
** Started on  Thu Oct  6 09:53:52 2016 Cornolti Thibaut
** Last update Sun Nov  6 22:31:43 2016 yann probst
*/

int	my_swap(int *a, int *b)
{
  int	b_tmp;

  b_tmp = *b;
  *b = *a;
  *a = b_tmp;
  return (0);
}
