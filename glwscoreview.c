/*
 * glwscoreview.c
 *
 *  Created on: 21.05.2010
 *      Author: cdev
 */

#include "widgets.h"

void glw_scoreview_show(GLWScoreView * glww)
{
	static char buf[10];
	sprintf(buf, "%u", glww->score);
	glCallList(glww->frame->call_list);
	render_string(glww->frame->cx, glww->frame->cy, buf, 0.7, text);
}

GLWScoreView * glw_scoreview_make(GLuint x, GLuint y, GLfloat alpha)
{
	GLWScoreView * glww = (GLWScoreView *)malloc(sizeof(GLWScoreView));
	glww->frame = glw_frame_make(x, y, 10 * text->h, text->h, alpha);
	glww->score = 0;
	return glww;
}
