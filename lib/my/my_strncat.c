/*
** my_strncat.c for my_strncat in /home/thibrex/delivery/CPool_Day07
** 
** Made by Cornolti Thibaut
** Login   <thibrex@epitech.net>
** 
** Started on  Tue Oct 11 12:26:27 2016 Cornolti Thibaut
** Last update Sun Nov  6 22:30:14 2016 yann probst
*/

char	*my_strncat(char *dest, char *src, int nb)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (dest[i] != 0)
      i += 1;
  while (src[j] != 0 && nb > 0)
    {
      dest[i + j] = src[j];
      j += 1;
      nb -= 1;
    }
  dest[i + j] = 0;
  return (dest);
}
