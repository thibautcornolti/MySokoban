/*
** my_strcapitalize.c for my_strcapitalize in /home/thibrex/delivery/CPool_Day06/tests
** 
** Made by Cornolti Thibaut
** Login   <thibrex@epitech.net>
** 
** Started on  Mon Oct 10 13:02:45 2016 Cornolti Thibaut
** Last update Sun Nov  6 22:27:09 2016 yann probst
*/

#include "my.h"

static void	check(char llc, char lc, char *str)
{
  if ((llc == '.' || llc == ';' ||
       llc == '?' || llc == '!' ||
       llc == ',') && *str >= 'a' && *str <= 'z' &&
      lc == ' ')
    *str -= 32;
  else if ((lc == '-' || lc == '+' || lc == ' ' || lc == '['
	    || lc == ']')
	   && *str >= 'a' && *str <= 'z')
    *str -= 32;
  else if (llc == 0 && lc == 0)
    *str -= 32;
}

char	*my_strcapitalize(char *str)
{
  char	last_last_char;
  char	last_char;
  int	i;

  i = 0;
  last_last_char = '\0';
  last_char = '\0';
  my_strlowcase(str);
  while (str[i] != 0)
    {
      check(last_last_char, last_char, str + i);
      last_last_char = last_char;
      last_char = str[i];
      i += 1;
    }
  return (str);
}
