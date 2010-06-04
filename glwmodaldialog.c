/*
 * glwmodaldialog.c
 *
 *  Created on: 22.05.2010
 *      Author: cdev
 */

#include "widgets.h"

GLWModalDialog * glw_modaldialog_make(GLuint x, GLuint y,
		GLfloat a, GLfloat ab,
		char * d, char * db1, char * db2,
		glw_action h1, glw_action h2)
{
	GLWModalDialog * glww = (GLWModalDialog *)malloc(sizeof(GLWModalDialog));
	glww->active = false;
	glww->dialog = d;
	glww->frame = glw_frame_make(x, y, strlen(d) * text->h, 3 * text->h, a);
	glww->b1 = glw_button_make(glww->frame->cx - glww->frame->width / 4,
			glww->frame->cy - glww->frame->height / 2 - border, ab,
			db1, h1);
	glww->b2 = glw_button_make(glww->frame->cx + glww->frame->width / 4,
			glww->frame->cy - glww->frame->height / 2 - border, ab,
			db2, h2);
	return glww;
}

void glw_modaldialog_action(GLWModalDialog * glww)
{
	if(glww->b1->focused ||
		glww->b2->focused)
	{
		glww->active = false;
		SDL_ShowCursor(0);
		glw_button_action(glww->b1);
		glw_button_action(glww->b2);
	}
}

void glw_modaldialog_raise(GLWModalDialog * glww)
{
	SDL_ShowCursor(1);
	glww->active = true;
}

void glw_modaldialog_focus(GLWModalDialog * glww, GLuint x, GLuint y)
{
	glw_button_focus(glww->b1, x, y);
	glw_button_focus(glww->b2, x, y);
}

void glw_modaldialog_show(GLWModalDialog * glww)
{
	if(glww->active)
	{
		glCallList(glww->frame->call_list);
		render_string(glww->frame->cx, glww->frame->cy, glww->dialog, 0.7, text);
		glw_button_show(glww->b1);
		glw_button_show(glww->b2);
	}
}
