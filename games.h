/*
 * games.h
 *
 *  Created on: 05.05.2010
 *      Author: cdev
 */




#ifndef GAMES_H_
#define GAMES_H_

#ifdef __MINGW32__
#include <windows.h>
#endif
#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

typedef void (* action)(void);

typedef struct
{
	GLuint screen_width;
	GLuint screen_height;
	action next_frame;
	action draw_frame;
	action draw_interface;
	action event_poller;
} GameContext;

extern GameContext global_context;

void switch_to_single();
void switch_to_multi();
void switch_to_score();
void switch_to_menu();
void switch_to_settings();

typedef struct
{
	GLfloat x;
	GLfloat z;
	GLfloat vx;
	GLfloat vz;
} Ball;

Ball * make_ball();
void ball_wall_reflect(Ball *);
void ball_normalize_speed(Ball *);

typedef struct
{
    GLfloat x;
    GLfloat z;
    GLfloat lvx;
    GLfloat rvx;
} Racket;

void racket_wall(Racket *);
Racket * make_racket(GLfloat, GLfloat);
void collide_with_ball(Racket *, Ball *);

void init_glgame();
void game_loop();
void halt_game();

void draw_ball(Ball *);
void draw_racket(Racket *);
void draw_field();

extern SDLKey first_player_left_key;
extern SDLKey first_player_right_key;
extern SDLKey second_player_left_key;
extern SDLKey second_player_right_key;
extern SDLKey player_left_key;
extern SDLKey player_right_key;

extern GLuint fsaa[];
extern GLfloat font_prec[];
extern GLsizei mmax_ball[];
extern GLuint settings_magic;

#endif /* GAMES_H_ */
