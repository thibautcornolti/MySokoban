/*
** my_is_prime.c for my_is_prime in /home/thibrex/delivery/CPool_Day05/tests
** 
** Made by Cornolti Thibaut
** Login   <thibrex@epitech.net>
** 
** Started on  Fri Oct  7 17:44:58 2016 Cornolti Thibaut
** Last update Sun Nov  6 21:34:07 2016 Thibaut Cornolti
*/

static int	my_sqrt(int nb)
{
  int		sqrt;

  sqrt = nb;
  while (sqrt * sqrt > nb || sqrt != sqrt * sqrt / sqrt)
      sqrt /= 2;
  return (sqrt*2);
}

int	my_is_prime(int nb)
{
  int	i;
  int	sqrt;

  sqrt = my_sqrt(nb);
  i = 2;
  while (sqrt >= i)
    {
      if (nb % i == 0)
	return (0);
      i += 1;
    }
  return (1);
}
