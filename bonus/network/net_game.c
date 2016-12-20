/*
** net_game.c for my_sokoban in /home/thibrex/Dropbox/delivery/PSU/PSU_2016_my_sokoban/bonus
** 
** Made by Thibaut Cornolti
** Login   <thibaut.cornolti@epitech.eu>
** 
** Started on  Sat Dec 17 14:55:33 2016 Thibaut Cornolti
** Last update Sun Dec 18 17:49:06 2016 Thibaut Cornolti
*/

#include "soko.h"

static int	check_net(t_game *g)
{
  int		i;
  int		j;

  i = -1;
  while (g->map[++i])
    {
      j = -1;
      while (g->map[i][++j])
	if (g->map[i][j] == 'S')
	  {
	    g->map[i][j] = ' ';
	    g->splayer.x = j;
	    g->splayer.y = i;
	    return (1);
	  }
    }
  return (0);
}

static void	update_box(t_game *g)
{
  size_t	received;

  if (!g->server)
    {
      if (sfTcpSocket_send(g->socket, &(g->packet),
			   sizeof(g->packet)) == sfSocketError)
	start_menu(g, "Connection timeout", NULL);
      g->packet.i = -1;
      if (sfTcpSocket_receive(g->socket, g->box,
			      sizeof(g->box) * get_box_len(g),
			      &received) == sfSocketError)
	start_menu(g, "Connection timeout", NULL);
    }
  else
    {
      if (sfTcpSocket_receive(g->socket, &(g->packet),
			      sizeof(g->packet),
			      &received) == sfSocketError)
	start_menu(g, "Connection timeout", NULL);
      if (g->packet.i >= 0)
	g->box[g->packet.i] = g->packet.box;
      if (sfTcpSocket_send(g->socket, g->box,
			   sizeof(g->box) * get_box_len(g)) == sfSocketError)
	start_menu(g, "Connection timeout", NULL);
    }
}

void		update_server(t_game *g)
{
  size_t	received;

  if (g->server == -1)
    return ;
  if (sfTcpSocket_send(g->socket, &(g->player),
		       sizeof(g->player)) == sfSocketError)
    start_menu(g, "Connection timeout", NULL);
  if (sfTcpSocket_receive(g->socket, &(g->splayer),
			  sizeof(g->splayer),
			  &received) == sfSocketError)
    start_menu(g, "Connection timeout", NULL);
  update_box(g);
}

void		start_server(t_game *g)
{
  sfUint8	size;

  if (!check_net(g))
    g->server = -1;
  if (g->server != 1)
    return ;
  g->listener = sfTcpListener_create();
  if (sfTcpListener_listen(g->listener, 51508) != sfSocketDone)
    start_menu(g, "Connection refused", NULL);
  if (sfTcpListener_accept(g->listener,
			   &(g->socket)) == sfSocketError)
    start_menu(g, "Connection refused", NULL);
  size = my_strlen(g->filepath);
  if (sfTcpSocket_send(g->socket, &size,
		       sizeof(sfUint8)) == sfSocketError)
    start_menu(g, "Connection timeout", NULL);
  if (sfTcpSocket_send(g->socket, g->filepath,
		       size) == sfSocketError)
    start_menu(g, "Connection timeout", NULL);
}
