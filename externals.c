/*
 * externals.c
 *
 *  Created on: 22.05.2010
 *      Author: cdev
 */

#include "widgets.h"
#include "games.h"
#include "interfaces.h"

FontLibrary * text;
GLuint border;
GameContext global_context;
SDLKey first_player_left_key = SDLK_a;
SDLKey first_player_right_key = SDLK_d;
SDLKey second_player_left_key = SDLK_l;
SDLKey second_player_right_key = SDLK_j;
SDLKey player_left_key = SDLK_a;
SDLKey player_right_key = SDLK_l;
GLuint fsaa[] = {0, 2, 4, 6};
GLfloat font_prec[] = { 4.0, 16.0, 64.0 };
GLsizei mmax_ball[] = { 3, 7, 10, -1};
GLuint settings_magic = 0xfaadfeed;

GLWButton * menu_single_button;
GLWButton * menu_multi_button;
GLWButton * menu_score_button;
GLWButton * menu_settings_button;
GLWButton * menu_exit_button;

GLWScoreView * single_score;
GLWMenu * single_menu;
GLWModalDialog * single_dialog;

GLWScoreView * multi_first_score;
GLWScoreView * multi_second_score;
GLWMenu * multi_menu;
GLWModalDialog * multi_dialog;

GLWScore * score_s[5];
GLWFrame * score_frame;
GLWButton * score_clean;
GLWButton * score_ret;

GLWChooser * settings_fsaa;
GLWChooser * settings_font;
GLWChooser * settings_mmax;
GLWButton * settings_ret;
