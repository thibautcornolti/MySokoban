/*
** my_memset.c for my_memset in /home/thibrex
** 
** Made by Thibaut Cornolti
** Login   <thibaut.cornolti@epitech.eu>
** 
** Started on  Mon Oct 24 21:52:16 2016 Thibaut Cornolti
** Last update Tue Oct 25 13:18:26 2016 Thibaut Cornolti
*/

void	*my_memset(void *src, int c, int n)
{
  int	i;

  i = 0;
  while (i < n)
    {
      ((int *)src)[i] = c;
      i += 1;
    }
  return (src);
}
