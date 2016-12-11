/*
** my_strcat.c for my_strcat in /home/thibrex/delivery/CPool_Day07
**
** Made by Cornolti Thibaut
** Login   <thibrex@epitech.net>
**
** Started on  Tue Oct 11 12:11:27 2016 Cornolti Thibaut
** Last update Fri Oct 28 16:25:53 2016 Thibaut Cornolti
*/

char	*my_strcat(char *dest, char *src)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (dest[i] != 0)
      i += 1;
  while (src[j] != 0)
    {
      dest[i + j] = src[j];
      j += 1;
    }
  dest[i + j] = 0;
  return (dest);
}
