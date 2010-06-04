/*
 * multi.c
 *
 *  Created on: 06.05.2010
 *      Author: cdev
 */
#include "games.h"
#include "widgets.h"
#include "interfaces.h"

static Ball * ball = NULL;
static Racket * first_player = NULL;
static Racket * second_player = NULL;
static bool first_lm = false;
static bool first_rm = false;
static bool second_lm = false;
static bool second_rm = false;

static void update_state()
{

	if(get_mmax() > 0 && (multi_first_score->score >= get_mmax()
			|| multi_second_score->score >= get_mmax()))
	{
		glw_modaldialog_raise(multi_dialog);
	}
    if(ball->z > 2.1f || ball->z < - 2.1f)
    {
    	ball->x = 0.0;
    	ball->z = (ball->z > 0)? 1.8 : -1.8;
    	ball->vx = 0.0;
    	ball->vz = (ball->z > 0)? -0.08f : 0.08f;
        if(ball->z > 0)
        	multi_second_score->score += 1;
        else
        	multi_first_score->score += 1;
    }

}

static void multi_draw_interface()
{
	glw_scoreview_show(multi_first_score);
	glw_scoreview_show(multi_second_score);
	glw_modaldialog_show(multi_dialog);
	glw_menu_show(multi_menu);
}

static void multi_draw_frame()
{
    glPushMatrix();
		glTranslated(-3.2f, 0.0f, -7.0f);
		glScalef(3.0f, 3.0f, 1.0f);
		glRotatef(30.0, 1.0, 0.0, 0.0);
		draw_field();
		draw_ball(ball);
		draw_racket(first_player);
		draw_racket(second_player);
    glPopMatrix();
    glPushMatrix();
        glTranslated(3.2f, 0.0f, -7.0f);
        glRotatef(180.0f, 0.0f, 1.0f, 0.0f);
        glScalef(3.0f, 3.0f, 1.0f);
        glRotatef(-30.0, 1.0, 0.0, 0.0);
        draw_field();
        draw_ball(ball);
        draw_racket(first_player);
        draw_racket(second_player);
   glPopMatrix();
}

static void multi_next_frame()
{
	if(multi_dialog->active || multi_menu->showed)
		return;
    if(!first_lm)
        first_player->lvx = 0.0f;
    else
        first_player->lvx -= (fabs(first_player->lvx) < 0.1f)? 0.004f : 0.0f;
    if(!first_rm)
        first_player->rvx = 0.0f;
    else
        first_player->rvx += (fabs(first_player->rvx) < 0.1f)? 0.004f : 0.0f;
    if(!second_lm)
        second_player->lvx = 0.0f;
    else
        second_player->lvx -= (fabs(second_player->lvx) < 0.1f)? 0.004f : 0.0f;
    if(!second_rm)
        second_player->rvx = 0.0f;
    else
        second_player->rvx += (fabs(second_player->rvx) < 0.1f)? 0.004f : 0.0f;
    racket_wall(first_player);
    racket_wall(second_player);
    collide_with_ball(first_player, ball);
    collide_with_ball(second_player, ball);
    ball_wall_reflect(ball);
    ball_normalize_speed(ball);
    first_player->x += first_player->rvx + first_player->lvx;
    second_player->x += second_player->rvx + second_player->lvx;
    ball->x += ball->vx;
    ball->z += ball->vz;
    update_state();
}

static void multi_event()
{
	SDL_Event event;
	while(SDL_PollEvent(&event))
	{
		if(event.type == SDL_MOUSEMOTION && (multi_dialog->active || multi_menu->showed))
		{
			if(multi_dialog->active)
				glw_modaldialog_focus(multi_dialog, event.motion.x,
						global_context.screen_height - event.motion.y);
			else if(multi_menu->showed)
				glw_menu_focus(multi_menu, event.motion.x,
						global_context.screen_height - event.motion.y);
		}
		else if(event.type == SDL_MOUSEBUTTONDOWN && (multi_dialog->active || multi_menu->showed))
		{
			if(multi_dialog->active)
				glw_modaldialog_action(multi_dialog);
			else if(multi_menu->showed)
				glw_menu_action(multi_menu);
		}
		else if((event.type == SDL_KEYUP || event.type == SDL_KEYDOWN) && !(multi_dialog->active))
		{
			SDLKey k = event.key.keysym.sym;
			if(k == SDLK_ESCAPE && event.type == SDL_KEYDOWN
					&& !multi_dialog->active)
			{
				if(multi_menu->showed)
					glw_menu_close(multi_menu);
				else
					glw_menu_raise(multi_menu);
			}
			else if(k == first_player_left_key)
				first_lm = event.type == SDL_KEYDOWN;
			else if(k == first_player_right_key)
				first_rm = event.type == SDL_KEYDOWN;
			else if(k == second_player_left_key)
				second_lm = event.type == SDL_KEYDOWN;
			else if(k == second_player_right_key)
				second_rm = event.type == SDL_KEYDOWN;
		}
		else if(event.type == SDL_QUIT)
		{
			halt_game();
		}
	}
}

void multi_release()
{
    free(ball);
    free(first_player);
    free(second_player);
    ball = NULL;
    first_player = NULL;
    second_player = NULL;
    multi_first_score->score = 0;
    multi_second_score->score = 0;
    switch_to_menu();
}

// TODO Remove this
void multi_continue(){}

void multi_new()
{
    ball->x = 0.0f;
    ball->z = 1.8f;
    ball->vx = 0.0f;
    ball->vz = - 0.08f;
    first_player->x = 0.0;
    first_player->z = 2.0;
    first_player->lvx = 0.0f;
    first_player->rvx = 0.0f;
    second_player->x = 0.0;
    second_player->z = - 2.0;
    second_player->lvx = 0.0f;
    second_player->rvx = 0.0f;
    multi_first_score->score = 0;
    multi_second_score->score = 0;
    first_lm = false;
    first_rm = false;
    second_lm = false;
    second_rm = false;
}

void switch_to_multi()
{
	SDL_ShowCursor(0);
    if(!ball) ball = make_ball();
    if(!first_player) first_player = make_racket(0.0f, 2.0f);
    if(!second_player) second_player = make_racket(0.0f, -2.0f);
    first_lm = false;
    first_rm = false;
    second_lm = false;
    second_rm = false;
    global_context.draw_frame = multi_draw_frame;
    global_context.draw_interface = multi_draw_interface;
    global_context.event_poller = multi_event;
    global_context.next_frame = multi_next_frame;
}

