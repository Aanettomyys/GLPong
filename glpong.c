/*
 * glpong.c
 *
 *  Created on: 05.05.2010
 *      Author: cdev
 */

#include "games.h"
#include "widgets.h"
#include "interfaces.h"

static void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(90.0, global_context.screen_width / (GLfloat)(global_context.screen_height), 1.0, 11.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    if(global_context.draw_frame) global_context.draw_frame();

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, global_context.screen_width, 0, global_context.screen_height);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glDisable(GL_DEPTH_TEST);
    if(global_context.draw_interface) global_context.draw_interface();
    glEnable(GL_DEPTH_TEST);
    glFlush();
}

static Uint32 next_frame(Uint32 interval, void * param)
{
    if(global_context.next_frame) global_context.next_frame();
    return interval;
}

void init_glgame()
{
	load_settings();
	static SDL_Surface * screen;
	SDL_Init(SDL_INIT_TIMER | SDL_INIT_VIDEO);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 4);
	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 4);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 4);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 4);
	SDL_GL_SetAttribute(SDL_GL_MULTISAMPLEBUFFERS, 1);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
	SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES, get_fsaa());
    SDL_WM_ToggleFullScreen(screen);
	screen = SDL_SetVideoMode(0, 0, 0, SDL_OPENGL | SDL_FULLSCREEN);
	global_context.screen_height = screen->h;
	global_context.screen_width = screen->w;
	SDL_WM_SetCaption("GLPong", NULL);
	SDL_AddTimer(20, next_frame, NULL);
    glClearColor(0.358f, 0.382f, 0.39f, 1.0f);
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glViewport(0,0, global_context.screen_width, global_context.screen_height);
    load_results_table();
    init_factory();
    init_settings();
    switch_to_menu();
}

void game_loop()
{
	for(;;)
	{
		global_context.event_poller();
		display();
		SDL_GL_SwapBuffers();
		SDL_Delay(10);
	}
}

void halt_game()
{
	write_results_table();
	write_settings();
	SDL_Quit();
}
