/*
 * glwassoclabel.c
 *
 *  Created on: 23.05.2010
 *      Author: cdev
 */
#include "widgets.h"

GLWAssocLabel * glw_assoc_label_make(GLuint x, GLuint y, GLuint w,
		GLfloat alpha, char * s, void * val)
{
	GLWAssocLabel * glww = (GLWAssocLabel *)malloc(sizeof(GLWAssocLabel));
	glww->anim = 0;
	glww->frame = false;
	glww->text = s;
	glww->val = val;
	glww->frame = glw_frame_make(x, y, w, text->h, alpha);
	return glww;
}

void glw_assoc_label_show(GLWAssocLabel * glww)
{
	if(glww->anim > 0 && !glww->focused)
		(glww->anim)--;
	glCallList(glww->frame->call_list);
	render_string(glww->frame->cx, glww->frame->cy, glww->text, glww->anim / 30.0, text);
}

GLboolean glw_assoc_label_focus(GLWAssocLabel * glww, GLuint x, GLuint y)
{
	GLboolean focus;
	focus = fabs(glww->frame->cx - x) <= (border + glww->frame->width / 2) &&
			fabs(glww->frame->cy - y) <= (border + glww->frame->height / 2);
	if(focus)
		glww->anim = 30;
	glww->focused = focus;
	return focus;
}
