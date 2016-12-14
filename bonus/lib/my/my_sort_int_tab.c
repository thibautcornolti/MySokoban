/*
** my_sort_int_tab.c for my_sort_int_tab in /home/thibrex/delivery/CPool_Day04
** 
** Made by Cornolti Thibaut
** Login   <thibrex@epitech.net>
** 
** Started on  Tue Oct 11 12:33:01 2016 Cornolti Thibaut
** Last update Sun Nov  6 22:25:51 2016 yann probst
*/

void	my_sort_int_tab(int *tab, int size)
{
  int	temp;
  int	i;
  int	j;

  i = 0;
  while (i < size)
    {
      j = i + 1;
      while (j < size)
	{
	  if (tab[j] > tab[i])
	    {
	      temp = tab[i];
	      tab[i] = tab[j];
	      tab[j] = temp;
	    }
	  j += 1;
	}
      i += 1;
    }
}
