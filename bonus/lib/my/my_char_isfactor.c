/*
** my_char_isfactor.c for my_char_isfactor in /home/thibrex
** 
** Made by Thibaut Cornolti
** Login   <thibaut.cornolti@epitech.eu>
** 
** Started on  Thu Oct 27 22:13:00 2016 Thibaut Cornolti
** Last update Thu Oct 27 22:14:14 2016 Thibaut Cornolti
*/

int	my_char_isfactor(char c)
{
  if (c == '*' || c == '/' || c == '%')
    return (1);
  return (0);
}
