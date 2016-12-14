/*
** my_str_islower.c for my_str_islower in /home/thibrex/delivery/CPool_Day06/tests
** 
** Made by Cornolti Thibaut
** Login   <thibrex@epitech.net>
** 
** Started on  Mon Oct 10 13:37:02 2016 Cornolti Thibaut
** Last update Sun Nov  6 22:28:42 2016 yann probst
*/

int	my_str_islower(char *str)
{
  int	i;

  i = 0;
  while (str[i] != 0)
    {
      if (!(str[i] >= 'a' && str[i] <= 'z'))
	return (0);
      i += 1;
    }
  return (1);
}
