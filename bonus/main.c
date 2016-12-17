/*
** main.c for my_sokoban in /home/thibrex/delivery/PSU/PSU_2016_my_sokoban
** 
** Made by Thibaut Cornolti
** Login   <thibaut.cornolti@epitech.eu>
** 
** Started on  Tue Dec  6 10:05:11 2016 Thibaut Cornolti
** Last update Sat Dec 17 17:27:45 2016 Thibaut Cornolti
*/

#include "soko.h"

static void	my_initscr()
{
  initscr();
  noecho();
  cbreak();
  curs_set(0);
  keypad(stdscr, TRUE);
  nodelay(stdscr, TRUE);
}

void		stop_game(t_game *g)
{
  if (g != NULL)
    {
      FMOD_Sound_Release(g->f_move);
      FMOD_Sound_Release(g->f_win);
      FMOD_Sound_Release(g->f_lose);
      FMOD_Sound_Release(g->f_check);
      FMOD_System_Close(g->f_sys);
      FMOD_System_Release(g->f_sys);
    }
  endwin();
  exit(0);
}

void		restart(t_game *g)
{
  load_file(g->filepath, g);
  start_game(g);
}

static void	init_game(t_game *g)
{
  g->height = 0;
  g->width = 0;
  g->ip = NULL;
  g->splayer.x = -1;
  g->splayer.y = -1;
  g->server = 1;
  g->f_music = NULL;
}

int		main(int ac, char **av)
{
  t_game	game;

  FMOD_System_Create(&(game.f_sys));
  FMOD_System_Init(game.f_sys, 32, FMOD_INIT_NORMAL, NULL);
  FMOD_System_Update(game.f_sys);
  FMOD_System_CreateChannelGroup(game.f_sys, "zic", &(game.f_gmusic));
  FMOD_System_CreateSound(game.f_sys, "sounds/cut.mp3",
			  FMOD_CREATESAMPLE, NULL, &(game.f_move));
  FMOD_System_CreateSound(game.f_sys, "sounds/lose.mp3",
			  FMOD_CREATESAMPLE, NULL, &(game.f_lose));
  FMOD_System_CreateSound(game.f_sys, "sounds/win.mp3",
			  FMOD_CREATESAMPLE, NULL, &(game.f_win));
  FMOD_System_CreateSound(game.f_sys, "sounds/check.mp3",
			  FMOD_CREATESAMPLE, NULL, &(game.f_check));
  ac += 1;
  game.filepath = av[1];
  init_game(&game);
  my_initscr();
  start_animation();
  start_menu(&game, NULL, NULL);
  endwin();
  return (0);
}
