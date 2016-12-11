/*
** my_strlowcase.c for my_strlowcase in /home/thibrex/delivery/CPool_Day06/tests
** 
** Made by Cornolti Thibaut
** Login   <thibrex@epitech.net>
** 
** Started on  Mon Oct 10 12:58:00 2016 Cornolti Thibaut
** Last update Sun Nov  6 22:30:01 2016 yann probst
*/

char	*my_strlowcase(char *str)
{
  int	i;

  i = 0;
  while (str[i] != 0)
    {
      if (str[i] >= 65 && str [i] <= 90)
	str[i] = str[i] + 32;
      i += 1;
    }
  return (str);
}
