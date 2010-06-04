/*
 * glwframe.c
 *
 *  Created on: 22.05.2010
 *      Author: cdev
 */

#include "widgets.h"

static void gen_call_for_frame(GLWFrame * glww)
{
	glww->call_list = glGenLists(1);
	GLuint x = glww->cx;
	GLuint y = glww->cy;
	GLuint w = glww->width / 2;
	GLuint h = glww->height / 2;
	glNewList(glww->call_list, GL_COMPILE);
		glColor4f(0.1, 0.1, 0.1, glww->back_alpha);
		glRectf(x - w, y + h, x + w, y - h);
		glRectf(x - w - border, y + h, x - w, y - h);
		glRectf(x - w, y - h, x + w, y - h - border);
		glRectf(x + w, y + h, x + w + border, y - h);
		glRectf(x - w, y + h + border, x + w, y + h);
		glBegin(GL_TRIANGLE_FAN);
			glVertex2f(x - w, y + h);
			for(GLuint i = 16; i <= 32; i++)
				glVertex2f(x - w + border * cos(3.14 * i / 32.0),
						   y + h + border * sin(3.14 * i / 32.0));
		glEnd();
		glBegin(GL_TRIANGLE_FAN);
			glVertex2f(x - w, y - h);
			for(GLuint i = 16; i <= 32; i++)
				glVertex2f(x - w + border * cos(3.14 * i / 32.0),
						   y - h - border * sin(3.14 * i / 32.0));
		glEnd();
		glBegin(GL_TRIANGLE_FAN);
			glVertex2f(x + w, y - h);
			for(GLuint i = 16; i <= 32; i++)
				glVertex2f(x + w - border * cos(3.14 * i / 32.0),
						   y - h - border * sin(3.14 * i / 32.0));
		glEnd();
		glBegin(GL_TRIANGLE_FAN);
			glVertex2f(x + w, y + h);
			for(GLuint i = 16; i <= 32; i++)
				glVertex2f(x + w - border * cos(3.14 * i / 32.0),
						   y + h + border * sin(3.14 * i / 32.0));
		glEnd();
	glEndList();
}

GLWFrame * glw_frame_make(GLuint x, GLuint y, GLuint w, GLuint h, GLfloat alpha)
{
	GLWFrame * glww = (GLWFrame *)malloc(sizeof(GLWFrame));
	glww->back_alpha = alpha;
	glww->cx = x;
	glww->cy = y;
	glww->height = h;
	glww->width = w;
	gen_call_for_frame(glww);
	return glww;
}
