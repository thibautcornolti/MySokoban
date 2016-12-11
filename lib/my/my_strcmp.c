/*
** my_strcmp.c for my_strcmp in /home/thibrex/delivery/CPool_Day06/tests
** 
** Made by Cornolti Thibaut
** Login   <thibrex@epitech.net>
** 
** Started on  Mon Oct 10 11:28:45 2016 Cornolti Thibaut
** Last update Sun Nov  6 22:27:33 2016 yann probst
*/

int	my_strcmp(char *s1, char *s2)
{
  int	i;

  i = 0;
  while (s1[i] != 0 || s2[i] != 0)
    {
      if (s1[i] != s2[i])
	return ((s1[i] - s2[i] < 0) ? -1 : 1);
      i += 1;
    }
  return (0);
}
