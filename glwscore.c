/*
 * glwscore.c
 *
 *  Created on: 22.05.2010
 *      Author: cdev
 */

#include "widgets.h"

void glw_score_show(GLWScore * glww)
{
	static char buf[10];
	sprintf(buf, "%u", *(glww->score));
	glCallList(glww->frame->call_list);
	render_string(glww->frame->cx, glww->frame->cy, buf, 0.7, text);
}

GLWScore * glw_score_make(GLuint x, GLuint y, GLfloat alpha, GLuint * ps)
{
	GLWScore * glww = (GLWScore *)malloc(sizeof(GLWScore));
	glww->frame = glw_frame_make(x, y, 10 * text->h, text->h, alpha);
	glww->score = ps;
	return glww;
}
