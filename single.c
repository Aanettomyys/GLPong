/*
 * single.c
 *
 *  Created on: 06.05.2010
 *      Author: cdev
 */

#include "games.h"
#include "widgets.h"
#include "interfaces.h"

static Ball * ball = NULL;
static Racket * player = NULL;
static bool left_moving = false;
static bool right_moving = false;

static void update_state()
{
    if(ball->z > 2.1f)
    {
    	glw_modaldialog_raise(single_dialog);
        update_results_table(single_score->score);
    }
    if(ball->z < -2.0f)
    {
        single_score->score += (unsigned long)100*(fabs(ball->vz) + fabs(ball->vx)) - 6;
        ball->vz = - ball->vz;
    }
}

static void single_draw_interface()
{
	glw_scoreview_show(single_score);
	glw_modaldialog_show(single_dialog);
	glw_menu_show(single_menu);
}

static void single_draw_frame()
{
    glPushMatrix();
    glTranslated(0.0f, 0.0f, -5.0f);
    glScalef(2.5f, 2.5f, 1.0f);
    glRotatef(30.0, 1.0, 0.0, 0.0);
    draw_field();
    draw_ball(ball);
    draw_racket(player);
    glPopMatrix();
 }

static void single_next_frame()
{
	if(single_dialog->active || single_menu->showed)
		return;
    if(!left_moving)
        player->lvx = 0.0f;
    else
        player->lvx -= (fabs(player->lvx) < 0.1f)? 0.004f : 0.0f;
    if(!right_moving)
        player->rvx = 0.0f;
    else
        player->rvx += (fabs(player->rvx) < 0.1f)? 0.004f : 0.0f;
    racket_wall(player);
    collide_with_ball(player, ball);
    ball_wall_reflect(ball);
    ball_normalize_speed(ball);
    player->x += player->rvx + player->lvx;
    ball->x += ball->vx;
    ball->z += ball->vz;
    update_state();
}

static void single_event()
{
	SDL_Event event;
	while(SDL_PollEvent(&event))
	{
		if(event.type == SDL_MOUSEMOTION && (single_dialog->active || single_menu->showed))
		{
			if(single_dialog->active)
				glw_modaldialog_focus(single_dialog, event.motion.x,
						global_context.screen_height - event.motion.y);
			else if(single_menu->showed)
				glw_menu_focus(single_menu, event.motion.x,
						global_context.screen_height - event.motion.y);
		}
		else if(event.type == SDL_MOUSEBUTTONDOWN && (single_dialog->active || single_menu->showed))
		{
			if(single_dialog->active)
				glw_modaldialog_action(single_dialog);
			else if(single_menu->showed)
				glw_menu_action(single_menu);
		}
		else if((event.type == SDL_KEYUP || event.type == SDL_KEYDOWN) && !(single_dialog->active))
		{
			SDLKey k = event.key.keysym.sym;
			if(k == SDLK_ESCAPE && event.type == SDL_KEYDOWN)
			{
				if(single_menu->showed)
					glw_menu_close(single_menu);
				else
					glw_menu_raise(single_menu);
			}
			else if(k == player_left_key && !single_menu->showed)
				left_moving = event.type == SDL_KEYDOWN;
			else if(k == player_right_key && !single_menu->showed)
				right_moving = event.type == SDL_KEYDOWN;
		}
		else if(event.type == SDL_QUIT)
		{
			halt_game();
		}
	}
}

// TODO Remove this
void single_continue(){}

void single_release()
{
    free(ball);
    free(player);
    ball = NULL;
    player = NULL;
    single_score->score = 0;
    switch_to_menu();
}

void single_new()
{
    ball->x = 0.0f;
    ball->z = 1.8f;
    ball->vx = 0.0f;
    ball->vz = - 0.08f;
    player->x = 0.0;
    player->z = 2.0;
    player->lvx = 0.0f;
    player->rvx = 0.0f;
    single_score->score = 0;
    left_moving = false;
    right_moving = false;
}

void switch_to_single()
{
	SDL_ShowCursor(0);
    if(!ball) ball = make_ball();
    if(!player) player = make_racket(0.0f, 2.0f);
    left_moving = false;
    right_moving = false;
    global_context.draw_frame = single_draw_frame;
    global_context.next_frame = single_next_frame;
    global_context.draw_interface = single_draw_interface;
    global_context.event_poller = single_event;
}
