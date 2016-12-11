/*
** my_str_isalpha.c for my_str_isalpha in /home/thibrex/delivery/CPool_Day06/tests
** 
** Made by Cornolti Thibaut
** Login   <thibrex@epitech.net>
** 
** Started on  Mon Oct 10 13:25:02 2016 Cornolti Thibaut
** Last update Sun Nov  6 22:28:27 2016 yann probst
*/

int	my_str_isalpha(char *str)
{
  int	i;

  i = 0;
  while (str[i] != 0)
    {
      if (!((str[i] >= 'a' && str[i] <= 'z') ||
	    (str[i] >= 'A' && str[i] <= 'Z')))
	return (0);
      i += 1;
    }
  return (1);
}
