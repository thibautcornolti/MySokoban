/*
** my_strncmp.c for my_strncmp in /home/thibrex/delivery/CPool_Day06/tests
** 
** Made by Cornolti Thibaut
** Login   <thibrex@epitech.net>
** 
** Started on  Mon Oct 10 11:40:45 2016 Cornolti Thibaut
** Last update Sun Nov  6 21:38:45 2016 Thibaut Cornolti
*/

static int	get_len(char *str)
{
  int	i;

  i = 0;
  while (str[i] != 0)
    i += 1;
  return (i);
}

int	my_strncmp(char *s1, char *s2, int n)
{
  int	l1;
  int	l2;
  int	n1;
  int	n2;

  l1 = 0;
  l2 = 0;
  n2 = get_len(s2);
  while (s1[n1] != 0 && n1 < n - 1 && n1 <= n2)
    {
      if (s1[n1] - s2[n1] != 0)
	return (s1[n1] - s2[n1]);
      l1 += s1[n1];
      n1 += 1;
    }
  n2 = 0;
  while (s2[n2] != 0 && n2 < n - 1 && n2 <= n1)
    {
      if (s1[n1] - s2[n1] != 0)
	return (s1[n1] - s2[n1]);
      l2 += s2[n2];
      n2 += 1;
    }
  return (l1 - l2);
}
