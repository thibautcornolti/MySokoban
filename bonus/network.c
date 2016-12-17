/*
** network.c for my_sokoban in /home/thibrex/Dropbox/delivery/PSU/PSU_2016_my_sokoban/bonus
** 
** Made by Thibaut Cornolti
** Login   <thibaut.cornolti@epitech.eu>
** 
** Started on  Sat Dec 17 12:43:29 2016 Thibaut Cornolti
** Last update Sat Dec 17 17:30:03 2016 Thibaut Cornolti
*/

#include "soko.h"

static void	refresh_network(t_game *g, char *msg)
{
  clear();
  show_title(g);
  attron(COLOR_PAIR(1));
  if (msg != NULL)
    mvprintw(LINES / 2 - 5, COLS / 2 - my_strlen(msg) / 2, "%s", msg);
  attroff(COLOR_PAIR(1));
  mvprintw(LINES / 2, COLS / 2 - 8, "IP: ");
  if (g->ip != NULL)
    mvprintw(LINES / 2, COLS / 2 - 4, g->ip);
  create_box(LINES / 2 - 3, COLS / 2 - 20, 7, 40);
  refresh();
}

static void	write_ip(t_game *g, int ch)
{
  int		len;

  len = my_strlen(g->ip);
  if (len >= 15)
    return ;
  g->ip[len] = ch;
  g->ip[len + 1] = 0;
}

static void	connect(t_game *g)
{
  sfIpAddress	ip;
  sfTime	t;
  sfUint8	size;
  size_t	received;

  ip = sfIpAddress_fromString(g->ip);
  t.microseconds = 3000;
  g->socket = sfTcpSocket_create();
  g->status = sfTcpSocket_connect(g->socket, ip, 51508, t);
  if (g->status != sfSocketDone)
    choice_connect(g, "Connection refused");
  g->server = 0;
  if (sfTcpSocket_receive(g->socket, &size,
			  sizeof(sfUint8),
			  &received) != sfSocketDone)
    start_menu(g, "Connection timeout", NULL);
  g->filepath = malloc(sizeof(char) * size);
  if (sfTcpSocket_receive(g->socket, g->filepath,
			  size,
			  &received) != sfSocketDone)
    start_menu(g, "Connection timeout2", NULL);
  start_game(g);
}

void		choice_connect(t_game *g, char *msg)
{
  int		ch;

  if (g->ip == NULL)
    {
      g->ip = malloc(sizeof(char) * 16);
      g->ip[0] = 0;
    }
  refresh_network(g, msg);
  while (1)
    {
      ch = getch();
      if (ch == 27)
	start_menu(g, NULL, NULL);
      else if (ch == 'q')
	stop_game(g);
      else if ((ch >= '0' && ch <= '9') || ch == '.')
	write_ip(g, ch);
      else if (ch == 263 && my_strlen(g->ip) != 0)
	g->ip[my_strlen(g->ip) - 1] = 0;
      else if (ch == '\n' || ch == ' ')
	connect(g);
      if (ch != -1)
	refresh_network(g, msg);
    }
}
