/*
** my_tablen.c for lib in /home/thibrex/delivery/PSU/PSU_2016_my_ls
** 
** Made by Thibaut Cornolti
** Login   <thibaut.cornolti@epitech.eu>
** 
** Started on  Wed Nov 23 15:18:14 2016 Thibaut Cornolti
** Last update Wed Nov 23 15:19:27 2016 Thibaut Cornolti
*/

int	my_strtablen(char **tab)
{
  int	len;

  len = -1;
  while (tab[++len]);
  return (len);
}
