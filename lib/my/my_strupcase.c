/*
** my_strupcase.c for my_strupcase in /home/thibrex/delivery/CPool_Day06/tests
** 
** Made by Cornolti Thibaut
** Login   <thibrex@epitech.net>
** 
** Started on  Mon Oct 10 12:49:00 2016 Cornolti Thibaut
** Last update Sun Nov  6 22:31:35 2016 yann probst
*/

char	*my_strupcase(char *str)
{
  int	i;

  i = 0;
  while (str[i] != 0)
    {
      if (str[i] >= 97 && str [i] <= 122)
	str[i] = str[i] - 32;
      i += 1;
    }
  return (str);
}
