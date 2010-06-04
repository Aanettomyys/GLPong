/*
 * mainmenu.c
 *
 *  Created on: 06.05.2010
 *      Author: cdev
 */

#include "games.h"
#include "widgets.h"
#include "interfaces.h"

static void menu_draw_interface()
{
	glw_button_show(menu_single_button);
	glw_button_show(menu_multi_button);
	glw_button_show(menu_score_button);
	glw_button_show(menu_settings_button);
	glw_button_show(menu_exit_button);
}

static void menu_event()
{
	SDL_Event event;
	while(SDL_PollEvent(&event))
	{
		if(event.type == SDL_MOUSEMOTION)
		{
			GLuint x = event.motion.x;
			GLuint y = global_context.screen_height - event.motion.y;
			glw_button_focus(menu_single_button, x, y);
			glw_button_focus(menu_multi_button, x, y);
			glw_button_focus(menu_score_button, x, y);
			glw_button_focus(menu_settings_button, x, y);
			glw_button_focus(menu_exit_button, x, y);
		}
		else if(event.type == SDL_MOUSEBUTTONDOWN)
		{
			glw_button_action(menu_single_button);
			glw_button_action(menu_multi_button);
			glw_button_action(menu_score_button);
			glw_button_action(menu_settings_button);

			glw_button_action(menu_exit_button);
		}
	}
}

void switch_to_menu()
{
	SDL_ShowCursor(1);
	global_context.draw_frame = NULL;
	global_context.draw_interface = menu_draw_interface;
	global_context.event_poller = menu_event;
	global_context.next_frame = NULL;
}
