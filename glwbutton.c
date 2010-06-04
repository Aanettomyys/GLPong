/*
 * glwbutton.c
 *
 *  Created on: 21.05.2010
 *      Author: cdev
 */

#include "widgets.h"
#include "games.h"

GLboolean glw_button_action(GLWButton * glww)
{
	GLboolean apply = glww->focused && glww->handler;
	if(apply)
	{
		glww->handler();
		glww->anim = 0;
		glww->focused = false;
	}
	return apply;
}

GLWButton * glw_button_make(GLuint x, GLuint y, GLfloat alpha, char * caption, glw_action handle)
{
	GLWButton * glww = (GLWButton *)malloc(sizeof(GLWButton));
	glww->focused = false;
	glww->handler = handle;
	glww->text = caption;
	glww->anim = 0;
	glww->frame = glw_frame_make(x, y, text->h * strlen(caption), text->h, alpha);
	return glww;
}

void glw_button_focus(GLWButton * glww, GLuint x, GLuint y)
{
	GLboolean focus = fabs(glww->frame->cx - x) <= (glww->frame->width / 2 + border) &&
			fabs(glww->frame->cy - y) <= (glww->frame->height / 2 + border);
	if(glww->focused != focus)
	{
		if((glww->focused = focus))
			glww->anim = 60;

	}
}

void glw_button_show(GLWButton * glww)
{
	if(!glww->focused && glww->anim > 0)
		(glww->anim)--;
	glCallList(glww->frame->call_list);
	render_string(glww->frame->cx, glww->frame->cy,
			glww->text, 1.0 * glww->anim / 60.0, text);
}
