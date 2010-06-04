/*
 * glwchooser.c
 *
 *  Created on: 23.05.2010
 *      Author: cdev
 */

#include "widgets.h"

GLWChooser * glw_chooser_make(GLuint x, GLuint y, GLsizei num, GLfloat alpha,
		char * cs, char ** css, void ** vals)
{
	GLWChooser * glww = (GLWChooser *)malloc(sizeof(GLWChooser));
	glww->figures = (GLWAssocLabel **)malloc(num * sizeof(GLWAssocLabel *));
	glww->expanded = false;
	glww->size = num;
	glww->name = glw_label_make(x, y, alpha, cs);
	GLsizei max_len = 0;
	GLsizei sbuf;
	for(GLsizei i = 0; i < num; i++)
		if(max_len < (sbuf = strlen(css[i])))
			max_len = sbuf;
	glww->frame = glw_frame_make(x + (text->h * max_len + 5 * border) / 2,
			y, glww->name->frame->width + text->h * max_len + 7 * border,
			text->h + 2 * border, alpha);
	x = glww->name->frame->cx + glww->name->frame->width / 2 + 4 * border + max_len * text->h / 2;
	glww->submenu = glw_frame_make(x, y, 2 * border + text->h * max_len,
			num * text->h + (3 * num - 1) * border, alpha);
	GLuint h = y + (glww->submenu->height - text->h) / 2 - border;
	for(GLsizei i = 0; i < num; i++)
	{
		glww->figures[i] = glw_assoc_label_make(x, h, max_len * text->h,
				alpha, css[i], vals[i]);
		h -= text->h + 3 * border;
	}
	glww->current = glw_assoc_label_make(x, y, max_len * text->h, alpha, css[0], vals[0]);
	return glww;
}

void glw_chooser_show(GLWChooser * glww)
{
	glCallList(glww->frame->call_list);
	glw_label_show(glww->name);
	if(glww->expanded)
	{
		glCallList(glww->submenu->call_list);
		for(GLsizei i = 0; i < glww->size; i++)
			glw_assoc_label_show(glww->figures[i]);
	}
	else
		glw_assoc_label_show(glww->current);
}

void glw_chooser_action(GLWChooser * glww, GLuint x, GLuint y)
{
	if(glww->expanded)
	{
		for(GLsizei i = 0; i < glww->size; i++)
			if(glww->figures[i]->focused)
			{
				glww->expanded = false;
				glww->figures[i]->focused = false;
				glww->current->text = glww->figures[i]->text;
				glww->figures[i]->anim = 0;
				glww->current->val = glww->figures[i]->val;
			}
	}
	else if(glww->current->focused)
	{
		glww->current->anim = 0;
		glww->expanded = true;
	}
	glw_chooser_focus(glww, x, y);
}

GLboolean glw_chooser_focus(GLWChooser * glww, GLuint x, GLuint y)
{
	if(glww->expanded)
	{
		for(GLsizei i = 0; i < glww->size; i++)
			if(glw_assoc_label_focus(glww->figures[i], x, y))
					return true;
	}
	else
		return glw_assoc_label_focus(glww->current, x, y);
}
