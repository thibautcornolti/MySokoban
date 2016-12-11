/*
** my_square_root.c for my_square_root in /home/thibrex/delivery/CPool_Day05/tests
** 
** Made by Cornolti Thibaut
** Login   <thibrex@epitech.net>
** 
** Started on  Fri Oct  7 15:08:27 2016 Cornolti Thibaut
** Last update Sun Nov  6 22:26:07 2016 yann probst
*/

int	my_square_root(int nb)
{
  int	i;
  int	x;

  i = 0;
  x = (nb > 80) ? 2 + nb / 1000 : 1;
  while (i <= nb / x)
    {
      if (i * i == nb)
	return (i);
      i += 1;
    }
  return (0);
}
