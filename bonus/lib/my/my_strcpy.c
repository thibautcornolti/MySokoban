/*
** my_strcpy.c for my_strcpy in /home/thibrex/delivery/CPool_Day06/tests
** 
** Made by Cornolti Thibaut
** Login   <thibrex@epitech.net>
** 
** Started on  Mon Oct 10 09:03:29 2016 Cornolti Thibaut
** Last update Sun Nov  6 21:38:55 2016 Thibaut Cornolti
*/

char	*my_strcpy(char *dest, char *src)
{
  int	i;

  i = 0;
  while (src[i] != 0)
    {
      dest[i] = src[i];
      i += 1;
    }
  dest[i] = 0;
  return (dest);
}
