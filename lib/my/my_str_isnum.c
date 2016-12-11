/*
** my_str_isnum.c for my_str_isnum in /home/thibrex/delivery/CPool_Day06/tests
** 
** Made by Cornolti Thibaut
** Login   <thibrex@epitech.net>
** 
** Started on  Mon Oct 10 13:37:02 2016 Cornolti Thibaut
** Last update Sun Nov  6 22:28:56 2016 yann probst
*/

int	my_str_isnum(char *str)
{
  int	i;

  i = 0;
  while (str[i] != 0)
    {
      if (!(str[i] >= '0' && str[i] <= '9'))
	return (0);
      i += 1;
    }
  return (1);
}
