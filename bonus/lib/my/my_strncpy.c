/*
** my_strncpy.c for my_strncpy in /home/thibrex/delivery/CPool_Day06/tests
** 
** Made by Cornolti Thibaut
** Login   <thibrex@epitech.net>
** 
** Started on  Mon Oct 10 09:42:17 2016 Cornolti Thibaut
** Last update Mon Oct 10 16:49:33 2016 Cornolti Thibaut
*/
char	*my_strncpy(char *dest, char *src, int n);

char	*my_strncpy(char *dest, char *src, int n)
{
  int	i;

  i = 0;
  while (i < n)
    {
      dest[i] = src[i];
      if (dest[i] == 0)
	return (dest);
      i += 1;
    }
  dest[i] = 0;
  return (dest);
}
