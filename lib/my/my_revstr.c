/*
** my_evil_str.c for my_evil_str in //home/thibrex/delivery/CPool_Day04
** 
** Made by Cornolti Thibaut
** Login   <thibrex@epitech.net>
** 
** Started on  Thu Oct  6 11:12:06 2016 Cornolti Thibaut
** Last update Sun Nov  6 22:24:18 2016 yann probst
*/

char	*my_revstr(char *str)
{
  int	length;
  int	count;
  char	temp;

  count = 0;
  while (str[count] != 0)
    {
      count += 1;
    }
  length = count;
  if (length > 1)
    {
      count = 0;
      while (count < length / 2)
	{
	  temp = str[count];
	  str[count] = str[length - count - 1];
	  str[length - count - 1] = temp;
	  count += 1;
	}
    }
  return (str);
}
