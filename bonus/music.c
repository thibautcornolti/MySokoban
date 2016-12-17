/*
** music.c for my_sokoban in /home/thibrex/Dropbox/delivery/PSU/PSU_2016_my_sokoban/bonus
** 
** Made by Thibaut Cornolti
** Login   <thibaut.cornolti@epitech.eu>
** 
** Started on  Fri Dec 16 23:10:51 2016 Thibaut Cornolti
** Last update Sat Dec 17 15:48:11 2016 Thibaut Cornolti
*/

#include <time.h>
#include "soko.h"

void		pause_music(t_game *g)
{
  FMOD_BOOL	boo;

  FMOD_ChannelGroup_GetPaused(g->f_gmusic, &boo);
  if (boo)
    FMOD_ChannelGroup_SetPaused(g->f_gmusic, 0);
  else
    FMOD_ChannelGroup_SetPaused(g->f_gmusic, 1);
}

void		stop_music(t_game *g)
{
  if (g->f_music != NULL)
    FMOD_Sound_Release(g->f_music);
  g->f_music = NULL;
}

void		start_music(t_game *g)
{
  char		**path;

  srand(time(NULL));
  path = malloc(sizeof(char *) * 5);
  path[0] = my_strdup("sounds/m1.mp3");
  path[1] = my_strdup("sounds/m2.mp3");
  path[2] = my_strdup("sounds/m3.mp3");
  path[3] = my_strdup("sounds/m4.mp3");
  path[4] = my_strdup("sounds/m5.mp3");
  stop_music(g);
  FMOD_System_CreateSound(g->f_sys, path[rand() % 4],
			  FMOD_2D | FMOD_CREATESTREAM,
			  NULL, &(g->f_music));
  FMOD_System_PlaySound(g->f_sys, g->f_music, g->f_gmusic, 0, NULL);
  FMOD_Sound_SetLoopCount(g->f_music, -1);
  FMOD_System_Update(g->f_sys);
}
