/*
** my_str_to_wordtab.c for my_str_to_wordtab in /home/thibrex/delivery/CPool_Day08
** 
** Made by Thibaut Cornolti
** Login   <thibaut.cornolti@epitech.eu@epitech.net>
** 
** Started on  Wed Oct 12 11:08:17 2016 Thibaut Cornolti
** Last update Fri Nov 25 14:54:04 2016 Thibaut Cornolti
*/

#include <stdlib.h>
#include "my.h"

static int	check_alphanum(char c)
{
  if (!(c >= '0' && c <= '9' ||
	c >= 'a' && c <= 'z' ||
	c >= 'A' && c <= 'Z'))
    return (0);
  else
    return (1);
}

static int	get_word_count(char *str)
{
  int		count;
  int		i;

  i = 0;
  count = 0;
  while (str[i] != 0)
    {
      if (check_alphanum(str[i]) == 0)
	count += 1;
      i += 1;
    }
  return (count + 1);
}

static char	**init_tab(char *str, char **tab)
{
  int		i;
  int		count;
  int		word;

  i = 0;
  count  = 0;
  word = 0;
  tab = malloc(sizeof(char *) *
	       (long unsigned int) get_word_count(str) + 1);
  if (tab == NULL)
    exit(my_puterror("error") + 84);
  while (str[i] != 0)
    {
      if (check_alphanum(str[i]) == 0 || word == 0)
	{
	  if ((tab[word] = malloc(sizeof(char) * count + 1)) == NULL)
	    exit(my_puterror("error") + 84);
	  word += 1;
	  count = 0;
	}
      	i+= 1;
	count += 1;
    }
  return (tab);
}

char	**my_str_to_wordtab(char *str)
{
  int	i;
  int	j;
  int	k;
  char	**wordtab;

  wordtab = init_tab(str, wordtab);
  i = -1;
  j = 0;
  k = 0;
  while (str[++i] != 0)
      if (check_alphanum(str[i]) == 0 && k != 0)
	{
	  k = 0;
	  j += 1;
	}
      else if (check_alphanum(str[i]) == 1)
	{
	  wordtab[j][k] = str[i];
	  wordtab[j][k + 1] = 0;
	  k += 1;
	}
  wordtab[j + 1] = NULL;
  return (wordtab);
}
