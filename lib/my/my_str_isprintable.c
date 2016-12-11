/*
** my_str_isprintable.c for my_str_isprintable in /home/thibrex/delivery/CPool_Day06/tests
** 
** Made by Cornolti Thibaut
** Login   <thibrex@epitech.net>
** 
** Started on  Mon Oct 10 14:01:02 2016 Cornolti Thibaut
** Last update Sun Nov  6 22:29:32 2016 yann probst
*/

int	my_str_isprintable(char *str)
{
  int	i;

  i = 0;
  while (str[i] != 0)
    {
      if (!(str[i] >= 32 && str[i] <= 126))
	return (0);
      i += 1;
    }
  return (1);
}
