/*
** my_str_contains.c for my_str_contains in /home/thibrex
** 
** Made by Thibaut Cornolti
** Login   <thibaut.cornolti@epitech.eu>
** 
** Started on  Thu Oct 27 18:42:20 2016 Thibaut Cornolti
** Last update Thu Oct 27 18:42:59 2016 Thibaut Cornolti
*/

int	my_str_contains(char c, char *str)
{
  int	i;

  i = 0;
  while (str[i] != 0)
    {
      if (str[i] == c)
	return (1);
      i += 1;
    }
  return (0);
}
