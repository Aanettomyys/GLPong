/*
 * glwmenu.c
 *
 *  Created on: 23.05.2010
 *      Author: cdev
 */

#include "widgets.h"

GLWMenu * glw_menu_make(GLuint x, GLuint y, GLsizei bnums, char ** captions, glw_action * handls)
{
	GLWMenu * glww = (GLWMenu *)malloc(sizeof(GLWMenu));
	glww->showed = false;
	glww->bnums = bnums;
	glww->buttons = (GLWButton **)malloc(sizeof(GLWButton *) * bnums);
	GLuint maxbsize = 0;
	GLuint h = y + (text->h * (bnums - 1) + border * 3 * (bnums - 1)) / 2;
	for(GLsizei i = 0; i < bnums; i++)
	{
		GLuint sbuf = strlen(captions[i]);
		if(sbuf > maxbsize) maxbsize = sbuf;
		glww->buttons[i] = glw_button_make(x, h, 0.3, captions[i], handls[i]);
		h -= 3 * border + text->h;
	}
	glww->frame = glw_frame_make(x, y, maxbsize * text->h + 2 * border,
			text->h * bnums + border * 3 * bnums, 0.3);
	return glww;
}

void glw_menu_focus(GLWMenu * glww, GLuint x, GLuint y)
{
	for(GLsizei i = 0; i < glww->bnums; i++)
		glw_button_focus(glww->buttons[i], x, y);
}
void glw_menu_action(GLWMenu * glww)
{
	for(GLsizei i = 0; i < glww->bnums; i++)
		if(glww->buttons[i]->focused)
		{
			glw_menu_close(glww);
			glw_button_action(glww->buttons[i]);
			return;
		}
}

void glw_menu_raise(GLWMenu * glww)
{
	SDL_ShowCursor(1);
	glww->showed = true;
}

void glw_menu_close(GLWMenu * glww)
{
	SDL_ShowCursor(0);
	glww->showed = false;
}

void glw_menu_show(GLWMenu * glww)
{
	if(glww->showed)
	{
		glCallList(glww->frame->call_list);
		for(GLsizei i = 0; i < glww->bnums; i++)
			glw_button_show(glww->buttons[i]);

	}
}
