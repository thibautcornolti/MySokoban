/*
** my_memset_str.c for my_memset_str in /home/thibrex
** 
** Made by Thibaut Cornolti
** Login   <thibaut.cornolti@epitech.eu>
** 
** Started on  Fri Oct 28 16:44:57 2016 Thibaut Cornolti
** Last update Fri Oct 28 16:45:20 2016 Thibaut Cornolti
*/

char	*my_memset_str(char *src, char c, int n)
{
  int	i;

  i = 0;
  while (i < n)
    {
      src[i] = c;
      i += 1;
    }
  return (src);
}
