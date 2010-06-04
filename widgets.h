/*
 * widgets.h
 *
 *  Created on: 20.05.2010
 *      Author: cdev
 */

#ifndef WIDGETS_H_
#define WIDGETS_H_
#ifdef __MINGW32__
#include <windows.h>
#endif
#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

typedef void (*glw_action)();

typedef struct
{
	GLsizei h;
	GLuint chars;
	GLfloat color[4];
} FontLibrary;

typedef struct
{
	GLuint width;
	GLuint height;
	GLuint cx;
	GLuint cy;
	GLfloat back_alpha;
	GLuint call_list;
} GLWFrame;

GLWFrame * glw_frame_make(GLuint, GLuint, GLuint, GLuint, GLfloat);

typedef struct
{
	GLWFrame * frame;
	GLboolean focused;
	char * text;
	GLsizei anim;
	glw_action handler;
} GLWButton;

GLboolean glw_button_action(GLWButton *);
GLWButton * glw_button_make(GLuint, GLuint, GLfloat, char *, glw_action);
void glw_button_focus(GLWButton *, GLuint, GLuint);
void glw_button_show(GLWButton *);

typedef struct
{
	GLWFrame * frame;
	GLuint score;
} GLWScoreView;

GLWScoreView * glw_scoreview_make(GLuint, GLuint, GLfloat);
void glw_scoreview_show(GLWScoreView *);

typedef struct
{
	GLWFrame * frame;
	GLuint * score;
} GLWScore;

GLWScore * glw_score_make(GLuint, GLuint, GLfloat, GLuint *);
void glw_score_show(GLWScore *);

typedef struct
{
	GLWFrame * frame;
	GLsizei bnums;
	GLboolean showed;
	GLWButton ** buttons;
} GLWMenu;

GLWMenu * glw_menu_make(GLuint, GLuint, GLsizei, char **, glw_action *);
void glw_menu_focus(GLWMenu *, GLuint, GLuint);
void glw_menu_action(GLWMenu *);
void glw_menu_show(GLWMenu *);
void glw_menu_raise(GLWMenu *);
void glw_menu_close(GLWMenu *);

typedef struct
{
	GLWFrame * frame;
	GLboolean active;
	char * dialog;
	GLWButton * b1;
	GLWButton * b2;
} GLWModalDialog;

GLWModalDialog * glw_modaldialog_make(GLuint, GLuint,
		GLfloat, GLfloat,
		char *, char *, char *,
		glw_action, glw_action);
void glw_modaldialog_action(GLWModalDialog *);
void glw_modaldialog_raise(GLWModalDialog *);
void glw_modaldialog_focus(GLWModalDialog *, GLuint, GLuint);
void glw_modaldialog_show(GLWModalDialog *);

typedef struct
{
	GLWFrame * frame;
	char * text;
} GLWLabel;

GLWLabel * glw_label_make(GLuint, GLuint, GLfloat, char *);
void glw_label_show(GLWLabel *);

typedef struct
{
	GLWFrame * frame;
	char * text;
	GLsizei anim;
	GLboolean focused;
	void * val;
} GLWAssocLabel;

GLWAssocLabel * glw_assoc_label_make(GLuint, GLuint, GLuint,
		GLfloat, char *, void *);
void glw_assoc_label_show(GLWAssocLabel *);
GLboolean glw_assoc_label_focus(GLWAssocLabel *, GLuint, GLuint);

typedef struct
{
	GLWFrame * frame;
	GLWFrame * submenu;
	GLWLabel * name;
	GLsizei size;
	GLboolean expanded;
	GLWAssocLabel * current;
	GLWAssocLabel ** figures;
} GLWChooser;

GLWChooser * glw_chooser_make(GLuint, GLuint, GLsizei, GLfloat,
		char *, char **, void **);
void glw_chooser_show(GLWChooser *);
void glw_chooser_action(GLWChooser *, GLuint, GLuint);
GLboolean glw_chooser_focus(GLWChooser *, GLuint, GLuint);


void init_factory();
FontLibrary * init_font(GLsizei);
void render_string(GLuint, GLuint, char *, GLfloat, FontLibrary *);

extern FontLibrary * text;
extern GLuint border;

#endif /* WIDGETS_H_ */
