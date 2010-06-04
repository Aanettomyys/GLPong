/*
 * glwlabel.c
 *
 *  Created on: 23.05.2010
 *      Author: cdev
 */

#include "widgets.h"

GLWLabel * glw_label_make(GLuint x, GLuint y, GLfloat alpha, char * s)
{
	GLWLabel * glww = (GLWLabel *)malloc(sizeof(GLWLabel));
	glww->text = s;
	glww->frame = glw_frame_make(x, y, strlen(s) * text->h, text->h, alpha);
	return glww;
}

void glw_label_show(GLWLabel * glww)
{
	glCallList(glww->frame->call_list);
	render_string(glww->frame->cx, glww->frame->cy, glww->text, 0.8, text);
}
