/*
 * font.c
 *
 *  Created on: 21.05.2010
 *      Author: cdev
 */

#include "widgets.h"
#include "interfaces.h"

static GLfloat cr = 0.5;
static GLfloat cb = 0.5;
static GLfloat cg = 0.5;
static GLfloat ca = 1.0;
static GLfloat prec = 4.0;

static void gen_sym_1_h_ru(FontLibrary * l)
{
	GLsizei h = l->h;
	glNewList(l->chars + 65 + 'À', GL_COMPILE);
		glLineWidth(h / 10.0);
		glPointSize(h / 10.0);
		glBegin(GL_LINES);
			glVertex2f(0.0, 0.0);
			glVertex2f(2.0 * h / 6.0, 0.0);
			glVertex2f(2.0 * h / 6.0, h / 2.0);
			glVertex2f(2.0 * h / 6.0, - h / 2.0);
			glVertex2f(2.0 * h / 6.0, h / 2.0);
			glVertex2f(- 2.0 * h / 6.0, - h / 2.0);
		glEnd();
		glBegin(GL_POINTS);
			glVertex2f(0.0, 0.0);
			glVertex2f(2.0 * h / 6.0, 0.0);
			glVertex2f(2.0 * h / 6.0, h / 2.0);
			glVertex2f(2.0 * h / 6.0, - h / 2.0);
			glVertex2f(2.0 * h / 6.0, h / 2.0);
			glVertex2f(- 2.0 * h / 6.0, - h / 2.0);
		glEnd();
	glEndList();
}

static void gen_sym_2_h_ru(FontLibrary * l)
{
	GLsizei h = l->h;
	glNewList(l->chars + 65 + 'Á', GL_COMPILE);
		glLineWidth(h / 10.0);
		glPointSize(h / 10.0);
		glBegin(GL_LINES);
			glVertex2f(- 2.0 * h / 6.0, h / 2.0);
			glVertex2f(h / 6.0, h / 2.0);
			glVertex2f(- 2.0 * h / 6.0, h / 2.0);
			glVertex2f(- 2.0 * h / 6.0, - h / 2.0);
			glVertex2f(- 2.0 * h / 6.0, 0.0);
			glVertex2f(h / 6.0, 0.0);
			glVertex2f(- 2.0 * h / 6.0, - h / 2.0);
			glVertex2f(h / 6.0, - h / 2.0);
		glEnd();
		glBegin(GL_POINTS);
			glVertex2f(- 2.0 * h / 6.0, h / 2.0);
			glVertex2f(h / 6.0, h / 2.0);
			glVertex2f(- 2.0 * h / 6.0, h / 2.0);
			glVertex2f(- 2.0 * h / 6.0, - h / 2.0);
			glVertex2f(- 2.0 * h / 6.0, 0.0);
			glVertex2f(h / 6.0, 0.0);
			glVertex2f(- 2.0 * h / 6.0, - h / 2.0);
			glVertex2f(h / 6.0, - h / 2.0);
		glEnd();
		glBegin(GL_LINE_STRIP);
			for(GLsizei i = 0; i <= prec * h; i++)
				glVertex2f(h / 6.0 + ( h / 6.0) * sin(3.14 * i / (prec * h)),
					- h / 4.0 + (h / 4.0) * cos(3.14 * i / (prec * h)));
		glEnd();
	glEndList();
}

static void gen_sym_3_h_ru(FontLibrary * l)
{
	GLsizei h = l->h;
	glNewList(l->chars + 65 + 'Â', GL_COMPILE);
		glLineWidth(h / 10.0);
		glPointSize(h / 10.0);
		glBegin(GL_LINES);
			glVertex2f(- 2.0 * h / 6.0, h / 2.0);
			glVertex2f( - h / 6.0, h / 2.0);
			glVertex2f(- 2.0 * h / 6.0, h / 2.0);
			glVertex2f(- 2.0 * h / 6.0, - h / 2.0);
			glVertex2f(- 2.0 * h / 6.0, 0.0);
			glVertex2f(0.0, 0.0);
			glVertex2f(- 2.0 * h / 6.0, - h / 2.0);
			glVertex2f(0.0, - h / 2.0);
		glEnd();
		glBegin(GL_POINTS);
			glVertex2f(- 2.0 * h / 6.0, h / 2.0);
			glVertex2f( - h / 6.0, h / 2.0);
			glVertex2f(- 2.0 * h / 6.0, h / 2.0);
			glVertex2f(- 2.0 * h / 6.0, - h / 2.0);
			glVertex2f(- 2.0 * h / 6.0, 0.0);
			glVertex2f(0.0, 0.0);
			glVertex2f(- 2.0 * h / 6.0, - h / 2.0);
			glVertex2f(0.0, - h / 2.0);
		glEnd();
		glBegin(GL_LINE_STRIP);
			for(GLsizei i = 0; i <= prec * h; i++)
				glVertex2f(- h / 6.0 + ( 2.0 * h / 6.0) * sin(3.14 * i / (prec * h)),
					 h / 4.0 + (h / 4.0) * cos(3.14 * i / (prec* h)));
		glEnd();
		glBegin(GL_LINE_STRIP);
			for(GLsizei i = 0; i <= prec * h; i++)
				glVertex2f((2.0 * h / 6.0) * sin(3.14 * i / (prec * h)),
					- h / 4.0 + (h / 4.0) * cos(3.14 * i / (prec * h)));
		glEnd();
	glEndList();
}

static void gen_sym_5_h_ru(FontLibrary * l)
{
	GLsizei h = l->h;
	glNewList(l->chars + 65 + 'Ä', GL_COMPILE);
		glLineWidth(h / 10.0);
		glPointSize(h / 10.0);
		glBegin(GL_LINES);
			glVertex2f(0.0, h / 2.0);
			glVertex2f(2.0 * h / 6.0, h / 2.0);
			glVertex2f(- h / 2.0, - h / 2.0);
			glVertex2f(h / 2.0, - h / 2.0);
			glVertex2f(2.0 * h / 6.0, h / 2.0);
			glVertex2f(2.0 * h / 6.0, - h / 2.0);
			glVertex2f(0.0, h / 2.0);
			glVertex2f(- 2.0 * h / 6.0, - h / 2.0);
		glEnd();
		glBegin(GL_POINTS);
			glVertex2f(0.0, h / 2.0);
			glVertex2f(2.0 * h / 6.0, h / 2.0);
			glVertex2f(- h / 2.0, - h / 2.0);
			glVertex2f(h / 2.0, - h / 2.0);
		glEnd();
	glEndList();
}

static void gen_sym_8_h_ru(FontLibrary * l)
{
	GLsizei h = l->h;
	glNewList(l->chars + 65 + 'Ç', GL_COMPILE);
		glLineWidth(h / 10.0);
		glPointSize(h / 10.0);
		glBegin(GL_POINTS);
			glVertex2f(0.0, 0.0);
			glVertex2f(0.0, - h / 2.0);
			glVertex2f(0.0, h / 2.0);
		glEnd();
		glBegin(GL_LINE_STRIP);
			for(GLsizei i = - prec * h / 2; i <= prec * h / 2; i ++)
				glVertex2f((2.0 * h / 6.0)*cos(3.14 * i / (prec * h)),
						    h / 4.0 + (h / 4.0) * sin(3.14 * i / (prec * h)));
		glEnd();
		glBegin(GL_LINE_STRIP);
			for(GLsizei i =  - prec * h / 2; i <= prec * h / 2; i ++)
				glVertex2f((2.0 * h / 6.0)*cos(3.14 * i / (prec * h)),
							- h / 4.0 + (h / 4.0) * sin(3.14 * i / (prec * h)));
		glEnd();
	glEndList();
}

static void gen_sym_11_h_ru(FontLibrary * l)
{
	GLsizei h = l->h;
	glNewList(l->chars + 65 + 'Ê', GL_COMPILE);
		glLineWidth(h / 10.0);
		glPointSize(h / 10.0);
		glBegin(GL_LINE_STRIP);
			glVertex2f(- 2.0 * h / 6.0, h / 2.0);
			glVertex2f(-2.0 * h / 6.0, - h / 2.0);
			glVertex2f(- 2.0 * h / 6.0, 0.0);
			glVertex2f(2.0 * h / 6.0, h / 2.0);
			glVertex2f(- 2.0 * h / 6.0, 0.0);
			glVertex2f(2.0 * h / 6.0, - h / 2.0);
		glEnd();
		glBegin(GL_POINTS);
			glVertex2f(- 2.0 * h / 6.0, h / 2.0);
			glVertex2f(-2.0 * h / 6.0, - h / 2.0);
			glVertex2f(2.0 * h / 6.0, h / 2.0);
			glVertex2f(2.0 * h / 6.0, - h / 2.0);
		glEnd();
	glEndList();
}


static void gen_sym_14_h_ru(FontLibrary * l)
{
	GLsizei h = l->h;
	glNewList(l->chars + 65 + 'Í', GL_COMPILE);
		glLineWidth(h / 10.0);
		glPointSize(h / 10.0);
		glBegin(GL_LINES);
			glVertex2f(- 2.0 * h / 6.0, h / 2.0);
			glVertex2f(- 2.0 * h / 6.0, - h / 2.0);
			glVertex2f(2.0 * h / 6.0, h / 2.0);
			glVertex2f(2.0 * h / 6.0, - h / 2.0);
			glVertex2f(- 2.0 * h / 6.0, 0.0);
			glVertex2f(2.0 * h / 6.0, 0.0);
		glEnd();
		glBegin(GL_POINTS);
			glVertex2f(- 2.0 * h / 6.0, h / 2.0);
			glVertex2f(- 2.0 * h / 6.0, - h / 2.0);
			glVertex2f(2.0 * h / 6.0, h / 2.0);
			glVertex2f(2.0 * h / 6.0, - h / 2.0);
		glEnd();
	glEndList();
}

static void gen_sym_15_h_ru(FontLibrary * l)
{
	GLsizei h = l->h;
	glNewList(l->chars + 65 + 'Î', GL_COMPILE);
		glLineWidth(h / 10.0);
		glPointSize(h / 10.0);
		glBegin(GL_LINE_STRIP);
			for(GLsizei i = 0; i <= prec * h; i ++)
				glVertex2f((2.0 * h / 6.0)*cos(6.28 * i / (prec * h)),
						   (h / 2.0) * sin(6.28 * i / (prec * h)));
		glEnd();
	glEndList();
}

static void gen_sym_16_h_ru(FontLibrary * l)
{
	GLsizei h = l->h;
	glNewList(l->chars + 65 + 'Ï', GL_COMPILE);
		glLineWidth(h / 10.0);
		glPointSize(h / 10.0);
		glBegin(GL_LINES);
			glVertex2f(- 2.0 * h / 6.0, h / 2.0);
			glVertex2f( 2.0 * h / 6.0, h / 2.0);
			glVertex2f(- 2.0 * h / 6.0, h / 2.0);
			glVertex2f(- 2.0 * h / 6.0, - h / 2.0);
			glVertex2f(2.0 * h / 6.0, h / 2.0);
			glVertex2f(2.0 * h / 6.0, - h / 2.0);
		glEnd();
		glBegin(GL_POINTS);
			glVertex2f(- 2.0 * h / 6.0, h / 2.0);
			glVertex2f( 2.0 * h / 6.0, h / 2.0);
			glVertex2f(- 2.0 * h / 6.0, - h / 2.0);
			glVertex2f(2.0 * h / 6.0, - h / 2.0);
		glEnd();
	glEndList();
}

static void gen_sym_17_h_ru(FontLibrary * l)
{
	GLsizei h = l->h;
	glNewList(l->chars + 65 + 'Ð', GL_COMPILE);
		glLineWidth(h / 10.0);
		glPointSize(h / 10.0);
		glBegin(GL_LINES);
			glVertex2f(- 2.0 * h / 6.0, h / 2.0);
			glVertex2f(0.0, h / 2.0);
			glVertex2f(- 2.0 * h / 6.0, h / 2.0);
			glVertex2f(- 2.0 * h / 6.0, - h / 2.0);
			glVertex2f(- 2.0 * h / 6.0, - h / 6.0);
			glVertex2f(0.0, - h / 6.0);
		glEnd();
		glBegin(GL_POINTS);
			glVertex2f(- 2.0 * h / 6.0, h / 2.0);
			glVertex2f(- 2.0 * h / 6.0, - h / 2.0);
		glEnd();
		glBegin(GL_LINE_STRIP);
			for(GLsizei i = 0; i <= prec * h; i++)
				glVertex2f(( 2.0 * h / 6.0) * sin(3.14 * i / (prec * h)),
					 h / 6.0 + (2.0 * h / 6.0) * cos(3.14 * i / (prec * h)));
		glEnd();
	glEndList();
}

static void gen_sym_18_h_ru(FontLibrary * l)
{
	GLsizei h = l->h;
	glNewList(l->chars + 65 + 'Ñ', GL_COMPILE);
		glLineWidth(h / 10.0);
		glPointSize(h / 10.0);
		glBegin(GL_LINE_STRIP);
			for(GLsizei i = 0; i <= prec * h; i ++)
				glVertex2f(- (2.0 * h / 6.0) * sin(3.14 * i / (prec * h)),
						   (h / 2.0) * cos(3.14 * i / (prec * h)));
		glEnd();
	glEndList();
}

static void gen_sym_19_h_ru(FontLibrary * l)
{
	GLsizei h = l->h;
	glNewList(l->chars + 65 + 'Ò', GL_COMPILE);
		glLineWidth(h / 10.0);
		glPointSize(h / 10.0);
		glBegin(GL_LINES);
			glVertex2f(- 2.0 * h / 6.0, h / 2.0);
			glVertex2f(2.0 * h / 6.0, h / 2.0);
			glVertex2f(0.0, h / 2.0);
			glVertex2f(0.0, - h / 2.0);
		glEnd();
		glBegin(GL_POINTS);
			glVertex2f(- 2.0 * h / 6.0, h / 2.0);
			glVertex2f(2.0 * h / 6.0, h / 2.0);
			glVertex2f(0.0, - h / 2.0);
		glEnd();
	glEndList();
}

static void gen_sym_1_l_ru(FontLibrary * l)
{
	GLsizei h = l->h;
	glNewList(l->chars + 65 + 'à', GL_COMPILE);
		glLineWidth(h / 10.0);
		glPointSize(h / 10.0);
		glBegin(GL_LINE_STRIP);
			for(GLsizei i = 0; i <=  prec * h; i ++)
				glVertex2f(0.0 + (2.0 * h / 6.0)*cos(6.28 * i / (prec * h)),
						   - h / 6.0 + (2.0 * h / 6.0) * sin(6.28 * i / (prec * h)));
		glEnd();
		glBegin(GL_LINES);
			glVertex2f(2.0 * h / 6.0, h / 6.0);
			glVertex2f(2.0 * h / 6.0, - h / 2.0);
		glEnd();
		glBegin(GL_POINTS);
			glVertex2f(2.0 * h / 6.0, h / 6.0);
			glVertex2f(2.0 * h / 6.0, - h / 2.0);
		glEnd();
	glEndList();
}

static void gen_sym_2_l_ru(FontLibrary * l)
{
	GLsizei h = l->h;
	glNewList(l->chars + 65 + 'á', GL_COMPILE);
		glLineWidth(h / 10.0);
		glPointSize(h / 10.0);
		glBegin(GL_LINES);
			glVertex2f(- 2.0 * h / 6.0, h / 6.0);
			glVertex2f(- 2.0 * h / 6.0, - h / 2.0);
			glVertex2f(- 2.0 * h / 6.0, - h / 6.0);
			glVertex2f(h / 6.0, - h / 6.0);
			glVertex2f(- 2.0 * h / 6.0, - h / 2.0);
			glVertex2f(h / 6.0, - h / 2.0);
			glVertex2f(- 2.0 * h / 6.0, h / 6.0);
			glVertex2f(2.0 * h / 6.0, h / 6.0);
		glEnd();
		glBegin(GL_LINE_STRIP);
			for(GLsizei i = 0; i <= prec * h; i++)
				glVertex2f(h / 6.0 + (h / 6.0) * sin(3.14 * i / (prec * h)),
						- 2.0 * h / 6.0 + (h / 6.0) * cos(3.14 * i / (prec * h)));
		glEnd();
		glBegin(GL_POINTS);
			glVertex2f(- 2.0 * h / 6.0, h / 6.0);
			glVertex2f(- 2.0 * h / 6.0, - h / 2.0);
			glVertex2f(2.0 * h / 6.0, h / 6.0);
		glEnd();
	glEndList();
}

static void gen_sym_3_l_ru(FontLibrary * l)
{
	GLsizei h = l->h;
	glNewList(l->chars + 65 + 'â', GL_COMPILE);
		glLineWidth(h / 10.0);
		glPointSize(h / 10.0);
		glBegin(GL_LINES);
			glVertex2f(- 2.0 * h / 6.0, h / 6.0);
			glVertex2f(- 2.0 * h / 6.0, - h / 2.0);
			glVertex2f(- 2.0 * h / 6.0, h / 6.0);
			glVertex2f(0.0, h / 6.0);
			glVertex2f(- 2.0 * h / 6.0, - h / 6.0);
			glVertex2f(h / 6.0, - h / 6.0);
			glVertex2f(- 2.0 * h / 6.0, - h / 2.0);
			glVertex2f(h / 6.0, - h / 2.0);
		glEnd();
		glBegin(GL_POINTS);
			glVertex2f(- 2.0 * h / 6.0, h / 6.0);
			glVertex2f(- 2.0 * h / 6.0, - h / 2.0);
		glEnd();
		glBegin(GL_LINE_STRIP);
			for(GLsizei i = 0; i <= prec * h; i++)
				glVertex2f((h / 6.0) * sin(3.14 * i / (prec * h)),
						(h / 6.0) * cos(3.14 * i / (prec * h)));
		glEnd();
		glBegin(GL_LINE_STRIP);
			for(GLsizei i = 0; i <= prec * h; i++)
				glVertex2f(h / 6.0 + (h / 6.0) * sin(3.14 * i / (prec * h)),
					- 2.0 * h / 6.0 + (h / 6.0) * cos(3.14 * i / (prec * h)));
		glEnd();
	glEndList();
}

static void gen_sym_4_l_ru(FontLibrary * l)
{
	GLsizei h = l->h;
	glNewList(l->chars + 65 + 'ã', GL_COMPILE);
		glLineWidth(h / 10.0);
		glPointSize(h / 10.0);
		glBegin(GL_LINES);
			glVertex2f(- 2.0 * h / 6.0, h / 6.0);
			glVertex2f(- 2.0 * h / 6.0, - h / 2.0);
			glVertex2f(- 2.0 * h / 6.0, h / 6.0);
			glVertex2f(h / 6.0, h / 6.0);
		glEnd();
		glBegin(GL_POINTS);
			glVertex2f(- 2.0 * h / 6.0, h / 6.0);
			glVertex2f(- 2.0 * h / 6.0, - h / 2.0);
			glVertex2f(h / 6.0, h / 6.0);
		glEnd();
	glEndList();
}

static void gen_sym_5_l_ru(FontLibrary * l)
{
	GLsizei h = l->h;
	glNewList(l->chars + 65 + 'ä', GL_COMPILE);
		glLineWidth(h / 10.0);
		glPointSize(h / 10.0);
		glBegin(GL_LINES);
			glVertex2f(0.0, h / 6.0);
			glVertex2f(2.0 * h / 6.0, h / 6.0);
			glVertex2f(- h / 2.0, - h / 2.0);
			glVertex2f(h / 2.0, - h / 2.0);
			glVertex2f(2.0 * h / 6.0, h / 6.0);
			glVertex2f(2.0 * h / 6.0, - h / 2.0);
			glVertex2f(0.0, h / 6.0);
			glVertex2f(- 2.0 * h / 6.0, - h / 2.0);
		glEnd();
		glBegin(GL_POINTS);
			glVertex2f(0.0, h / 6.0);
			glVertex2f(2.0 * h / 6.0, h / 6.0);
			glVertex2f(- h / 2.0, - h / 2.0);
			glVertex2f(h / 2.0, - h / 2.0);
		glEnd();
	glEndList();
}

static void gen_sym_6_l_ru(FontLibrary * l)
{
	GLsizei h = l->h;
	glNewList(l->chars + 65 + 'å', GL_COMPILE);
		glLineWidth(h / 10.0);
		glPointSize(h / 10.0);
		glBegin(GL_LINES);
			glVertex2f(- 2.0 * h / 6.0, - h / 6.0);
			glVertex2f(2.0 * h / 6.0, - h / 6.0);
		glEnd();
		glBegin(GL_POINTS);
			glVertex2f(2.0 * h / 6.0, - h / 6.0);
		glEnd();
		glBegin(GL_LINE_STRIP);
			for(GLsizei i = 0; i <=  3 * prec * h / 4.0; i ++)
				glVertex2f(0.0 + (2.0 * h / 6.0)*cos(6.28 * i / (prec * h)),
						   - h / 6.0 + (2.0 * h / 6.0) * sin(6.28 * i / (prec * h)));
		glEnd();
	glEndList();
}

static void gen_sym_7_l_ru(FontLibrary * l)
{
	GLsizei h = l->h;
	glNewList(l->chars + 65 + 'æ', GL_COMPILE);
		glLineWidth(h / 10.0);
		glPointSize(h / 10.0);
		glBegin(GL_LINES);
			glVertex2f(- 2.0 * h / 6.0, h / 6.0);
			glVertex2f(2.0 * h / 6.0, - h / 2.0);
			glVertex2f(- 2.0 * h / 6.0, - h / 2.0);
			glVertex2f(2.0 * h / 6.0, h / 6.0);
			glVertex2f(0.0, h / 6.0);
			glVertex2f(0.0, - h / 2.0);
		glEnd();
		glBegin(GL_POINTS);
			glVertex2f(- 2.0 * h / 6.0, h / 6.0);
			glVertex2f(2.0 * h / 6.0, - h / 2.0);
			glVertex2f(- 2.0 * h / 6.0, - h / 2.0);
			glVertex2f(2.0 * h / 6.0, h / 6.0);
			glVertex2f(0.0, h / 6.0);
			glVertex2f(0.0, - h / 2.0);
		glEnd();
	glEndList();
}

static void gen_sym_8_l_ru(FontLibrary * l)
{
	GLsizei h = l->h;
	glNewList(l->chars + 65 + 'ç', GL_COMPILE);
		glLineWidth(h / 10.0);
		glPointSize(h / 10.0);
		glBegin(GL_LINES);
			glVertex2f(- 2.0 * h / 6.0, h / 6.0);
			glVertex2f(h / 6.0, h / 6.0);
			glVertex2f(- 2.0 * h / 6.0, - h / 6.0);
			glVertex2f(h / 6.0, - h / 6.0);
			glVertex2f(- 2.0 * h / 6.0, - h / 2.0);
			glVertex2f(h / 6.0, - h / 2.0);
		glEnd();
		glBegin(GL_POINTS);
			glVertex2f(- 2.0 * h / 6.0, h / 6.0);
			glVertex2f(- 2.0 * h / 6.0, - h / 6.0);
			glVertex2f(- 2.0 * h / 6.0, - h / 2.0);
		glEnd();
		glBegin(GL_LINE_STRIP);
			for(GLsizei i = 0; i <= prec * h; i ++)
				glVertex2f( h / 6.0 + (h / 6.0) * sin(3.14 * i / (prec * h)),
						    (h / 6.0) * cos(3.14 * i / (prec * h)));
		glEnd();
		glBegin(GL_LINE_STRIP);
			for(GLsizei i = 0; i <= prec * h; i ++)
				glVertex2f(h / 6.0 + (h / 6.0) * sin(3.14 * i / (prec * h)),
							- 2.0 * h / 6.0 + (h / 6.0) * cos(3.14 * i / (prec * h)));
		glEnd();
	glEndList();
}

static void gen_sym_9_l_ru(FontLibrary * l)
{
	GLsizei h = l->h;
	glNewList(l->chars + 65 + 'è', GL_COMPILE);
		glLineWidth(h / 10.0);
		glPointSize(h / 10.0);
		glBegin(GL_LINES);
			glVertex2f(- 2.0 * h / 6.0, h / 6.0);
			glVertex2f(- 2.0 * h / 6.0, - h / 2.0);
			glVertex2f(2.0 * h / 6.0, h / 6.0);
			glVertex2f(2.0 * h / 6.0, - h / 2.0);
			glVertex2f(- 2.0 * h / 6.0, - h / 2.0);
			glVertex2f(2.0 * h / 6.0, h / 6.0);
		glEnd();
		glBegin(GL_POINTS);
			glVertex2f(- 2.0 * h / 6.0, h / 6.0);
			glVertex2f(- 2.0 * h / 6.0, - h / 2.0);
			glVertex2f(2.0 * h / 6.0, h / 6.0);
			glVertex2f(2.0 * h / 6.0, - h / 2.0);
		glEnd();
	glEndList();
}

static void gen_sym_10_l_ru(FontLibrary * l)
{
	GLsizei h = l->h;
	glNewList(l->chars + 65 + 'é', GL_COMPILE);
		glLineWidth(h / 10.0);
		glPointSize(h / 10.0);
		glBegin(GL_LINES);
			glVertex2f(- 2.0 * h / 6.0, h / 6.0);
			glVertex2f(- 2.0 * h / 6.0, - h / 2.0);
			glVertex2f(2.0 * h / 6.0, h / 6.0);
			glVertex2f(2.0 * h / 6.0, - h / 2.0);
			glVertex2f(- 2.0 * h / 6.0, - h / 2.0);
			glVertex2f(2.0 * h / 6.0, h / 6.0);
			glVertex2f(- h / 6.0, 2.0 * h / 6.0);
			glVertex2f(h / 6.0, 2.0 * h / 6.0);
		glEnd();
		glBegin(GL_POINTS);
			glVertex2f(- 2.0 * h / 6.0, h / 6.0);
			glVertex2f(- 2.0 * h / 6.0, - h / 2.0);
			glVertex2f(2.0 * h / 6.0, h / 6.0);
			glVertex2f(2.0 * h / 6.0, - h / 2.0);
			glVertex2f(- h / 6.0, 2.0 * h / 6.0);
			glVertex2f(h / 6.0, 2.0 * h / 6.0);
		glEnd();
	glEndList();
}

static void gen_sym_11_l_ru(FontLibrary * l)
{
	GLsizei h = l->h;
	glNewList(l->chars + 65 + 'ê', GL_COMPILE);
		glLineWidth(h / 10.0);
		glPointSize(h / 10.0);
		glBegin(GL_LINE_STRIP);
			glVertex2f(- 2.0 * h / 6.0, h / 6.0);
			glVertex2f(-2.0 * h / 6.0, - h / 2.0);
			glVertex2f(- 2.0 * h / 6.0, - h / 6.0);
			glVertex2f(2.0 * h / 6.0, h / 6.0);
			glVertex2f(- 2.0 * h / 6.0, - h / 6.0);
			glVertex2f(2.0 * h / 6.0, - h / 2.0);
		glEnd();
		glBegin(GL_POINTS);
			glVertex2f(- 2.0 * h / 6.0, h / 6.0);
			glVertex2f(-2.0 * h / 6.0, - h / 2.0);
			glVertex2f(2.0 * h / 6.0, h / 6.0);
			glVertex2f(2.0 * h / 6.0, - h / 2.0);
		glEnd();
	glEndList();
}

static void gen_sym_12_l_ru(FontLibrary * l)
{
	GLsizei h = l->h;
	glNewList(l->chars + 65 + 'ë', GL_COMPILE);
		glLineWidth(h / 10.0);
		glPointSize(h / 10.0);
		glBegin(GL_LINE_STRIP);
			glVertex2f(2 * h / 6.0, - h / 2.0);
			glVertex2f(2 * h / 6.0, h / 6.0);
			glVertex2f(0.0, h / 6.0);
			glVertex2f(- 2.0 * h / 6.0, - h / 2.0);
		glEnd();
		glBegin(GL_POINTS);
			glVertex2f(2 * h / 6.0, - h / 2.0);
			glVertex2f(2 * h / 6.0, h / 6.0);
			glVertex2f(0.0, h / 6.0);
			glVertex2f(- 2.0 * h / 6.0, - h / 2.0);
		glEnd();
	glEndList();
}

static void gen_sym_13_l_ru(FontLibrary * l)
{
	GLsizei h = l->h;
	glNewList(l->chars + 65 + 'ì', GL_COMPILE);
		glLineWidth(h / 10.0);
		glPointSize(h / 10.0);
		glBegin(GL_LINES);
			glVertex2f(- 2.0 * h / 6.0, h / 6.0);
			glVertex2f(- 2.0 * h / 6.0, - h / 2.0);
			glVertex2f(2.0 * h / 6.0, h / 6.0);
			glVertex2f(2.0 * h / 6.0, - h / 2.0);
			glVertex2f(- 2.0 * h / 6.0, h / 6.0);
			glVertex2f(0.0, - h / 6.0);
			glVertex2f(2.0 * h / 6.0, h / 6.0);
			glVertex2f(0.0, - h / 6.0);
		glEnd();
		glBegin(GL_POINTS);
			glVertex2f(- 2.0 * h / 6.0, h / 6.0);
			glVertex2f(- 2.0 * h / 6.0, - h / 2.0);
			glVertex2f(2.0 * h / 6.0, h / 6.0);
			glVertex2f(2.0 * h / 6.0, - h / 2.0);
			glVertex2f(0.0, - h / 6.0);
		glEnd();
	glEndList();
}

static void gen_sym_14_l_ru(FontLibrary * l)
{
	GLsizei h = l->h;
	glNewList(l->chars + 65 + 'í', GL_COMPILE);
		glLineWidth(h / 10.0);
		glPointSize(h / 10.0);
		glBegin(GL_LINES);
			glVertex2f(- 2.0 * h / 6.0, h / 6.0);
			glVertex2f(- 2.0 * h / 6.0, - h / 2.0);
			glVertex2f(2.0 * h / 6.0, h / 6.0);
			glVertex2f(2.0 * h / 6.0, - h / 2.0);
			glVertex2f(- 2.0 * h / 6.0, - h / 6.0);
			glVertex2f(2.0 * h / 6.0, - h / 6.0);
		glEnd();
		glBegin(GL_POINTS);
			glVertex2f(- 2.0 * h / 6.0, h / 6.0);
			glVertex2f(- 2.0 * h / 6.0, - h / 2.0);
			glVertex2f(2.0 * h / 6.0, h / 6.0);
			glVertex2f(2.0 * h / 6.0, - h / 2.0);
		glEnd();
	glEndList();
}

static void gen_sym_15_l_ru(FontLibrary * l)
{
	GLsizei h = l->h;
	glNewList(l->chars + 65 + 'î', GL_COMPILE);
		glLineWidth(h / 10.0);
		glPointSize(h / 10.0);
		glBegin(GL_LINE_STRIP);
			for(GLsizei i = 0; i <=  prec * h; i ++)
				glVertex2f(0.0 + (2.0 * h / 6.0)*cos(6.28 * i / (prec * h)),
						   - h / 6.0 + (2.0 * h / 6.0) * sin(6.28 * i / (prec * h)));
		glEnd();
	glEndList();
}

static void gen_sym_17_l_ru(FontLibrary * l)
{
	GLsizei h = l->h;
	glNewList(l->chars + 65 + 'ð', GL_COMPILE);
		glLineWidth(h / 10.0);
		glPointSize(h / 10.0);
		glBegin(GL_LINES);
			glVertex2f(- 2.0 * h / 6.0, h / 6.0);
			glVertex2f(- 2.0 * h / 6.0, - h / 2.0);
			glVertex2f(- 2.0 * h / 6.0, h / 6.0);
			glVertex2f(h / 6.0, h / 6.0);
			glVertex2f(- 2.0 * h / 6.0, - h / 6.0);
			glVertex2f(h / 6.0, - h / 6.0);
		glEnd();
		glBegin(GL_POINTS);
			glVertex2f(- 2.0 * h / 6.0, h / 6.0);
			glVertex2f(- 2.0 * h / 6.0, - h / 2.0);
		glEnd();
		glBegin(GL_LINE_STRIP);
			for(GLsizei i = 0; i <=  prec * h; i ++)
				glVertex2f(h / 6.0 + (h / 6.0) * sin(3.15 * i / (prec * h)),
						   (h / 6.0) * cos(3.14 * i / (prec * h)));
		glEnd();
	glEndList();
}

static void gen_sym_18_l_ru(FontLibrary * l)
{
	GLsizei h = l->h;
	glNewList(l->chars + 65 + 'ñ', GL_COMPILE);
		glLineWidth(h / 10.0);
		glPointSize(h / 10.0);
		glBegin(GL_LINE_STRIP);
			for(GLsizei i = 0; i <= prec * h; i ++)
				glVertex2f(- (2.0 * h / 6.0) * sin(3.14 * i / (prec * h)),
						   - h / 6.0 + (2.0 * h / 6.0) * cos(3.14 * i / (prec * h)));
		glEnd();
	glEndList();
}

static void gen_sym_19_l_ru(FontLibrary * l)
{
	GLsizei h = l->h;
	glNewList(l->chars + 65 + 'ò', GL_COMPILE);
		glLineWidth(h / 10.0);
		glPointSize(h / 10.0);
		glBegin(GL_LINES);
			glVertex2f(- 2.0 * h / 6.0, h / 6.0);
			glVertex2f(2.0 * h / 6.0, h / 6.0);
			glVertex2f(0.0, h / 6.0);
			glVertex2f(0.0, - h / 2.0);
		glEnd();
		glBegin(GL_POINTS);
			glVertex2f(- 2.0 * h / 6.0, h / 6.0);
			glVertex2f(2.0 * h / 6.0, h / 6.0);
			glVertex2f(0.0, - h / 2.0);
		glEnd();
	glEndList();
}

static void gen_sym_20_l_ru(FontLibrary * l)
{
	GLsizei h = l->h;
	glNewList(l->chars + 65 + 'ó', GL_COMPILE);
		glLineWidth(h / 10.0);
		glPointSize(h / 10.0);
		glBegin(GL_LINES);
			glVertex2f(- 2.0 * h / 6.0, h / 6.0);
			glVertex2f(0.0, - h / 6.0);
			glVertex2f(- 2.0 * h / 6.0, - h / 2.0);
			glVertex2f(2.0 * h / 6.0, h / 6.0);
		glEnd();
		glBegin(GL_POINTS);
			glVertex2f(- 2.0 * h / 6.0, h / 6.0);
			glVertex2f(- 2.0 * h / 6.0, - h / 2.0);
			glVertex2f(2.0 * h / 6.0, h / 6.0);
		glEnd();
	glEndList();
}

static void gen_sym_21_l_ru(FontLibrary * l)
{
	GLsizei h = l->h;
	glNewList(l->chars + 65 + 'ô', GL_COMPILE);
		glLineWidth(h / 10.0);
		glPointSize(h / 10.0);
		glBegin(GL_LINES);
			glVertex2f(0.0, 2.0 * h / 6.0);
			glVertex2f(0.0, - 4.0 * h / 6.0);
		glEnd();
		glBegin(GL_POINTS);
			glVertex2f(0.0, 2.0 * h / 6.0);
			glVertex2f(0.0, - 4.0 * h / 6.0);
		glEnd();
		glBegin(GL_LINE_STRIP);
			for(GLsizei i = 0; i <=  prec * h; i ++)
				glVertex2f(0.0 + (2.0 * h / 6.0)*cos(6.28 * i / (prec * h)),
						   - h / 6.0 + (2.0 * h / 6.0) * sin(6.28 * i / (prec * h)));
		glEnd();
	glEndList();
}

static void gen_sym_22_l_ru(FontLibrary * l)
{
	GLsizei h = l->h;
	glNewList(l->chars + 65 + 'õ', GL_COMPILE);
		glLineWidth(h / 10.0);
		glPointSize(h / 10.0);
		glBegin(GL_LINES);
			glVertex2f(- 2.0 * h / 6.0, h / 6.0);
			glVertex2f(2.0 * h / 6.0, - h / 2.0);
			glVertex2f(- 2.0 * h / 6.0, - h / 2.0);
			glVertex2f(2.0 * h / 6.0, h / 6.0);
		glEnd();
		glBegin(GL_POINTS);
			glVertex2f(- 2.0 * h / 6.0, h / 6.0);
			glVertex2f(2.0 * h / 6.0, - h / 2.0);
			glVertex2f(- 2.0 * h / 6.0, - h / 2.0);
			glVertex2f(2.0 * h / 6.0, h / 6.0);
		glEnd();
	glEndList();
}

static void gen_sym_24_l_ru(FontLibrary * l)
{
	GLsizei h = l->h;
	glNewList(l->chars + 65 + '÷', GL_COMPILE);
		glLineWidth(h / 10.0);
		glPointSize(h / 10.0);
		glBegin(GL_LINES);
			glVertex2f(2.0 * h / 6.0, h / 6.0);
			glVertex2f(2.0 * h / 6.0, - h / 2.0);
			glVertex2f(- h / 6.0, - h / 6.0);
			glVertex2f(2.0 * h / 6.0, - h / 6.0);
			glVertex2f(- 2.0 * h / 6.0, 0.0);
			glVertex2f(- 2.0 * h / 6.0, h / 6.0);
		glEnd();
		glBegin(GL_POINTS);
			glVertex2f(2.0 * h / 6.0, h / 6.0);
			glVertex2f(2.0 * h / 6.0, - h / 2.0);
			glVertex2f(- 2.0 * h / 6.0, h / 6.0);
		glEnd();
		glBegin(GL_LINE_STRIP);
			for(GLsizei i = 0; i <= prec * h / 2.0; i++)
				glVertex2f( - h / 6.0 - (h / 6.0) * sin(3.14 * i / (prec * h)),
							- (h / 6.0) * cos(3.14 * i / (prec * h)));
		glEnd();
	glEndList();
}

static void gen_sym_25_l_ru(FontLibrary * l)
{
	GLsizei h = l->h;
	glNewList(l->chars + 65 + 'ø', GL_COMPILE);
		glLineWidth(h / 10.0);
		glPointSize(h / 10.0);
		glBegin(GL_LINES);
			glVertex2f(- 2.0 * h / 6.0, - h / 2.0);
			glVertex2f(2.0 * h / 6.0, - h / 2.0);
			glVertex2f(- 2.0 * h / 6.0, - h / 2.0);
			glVertex2f(- 2.0 * h / 6.0, h / 6.0);
			glVertex2f(0.0, - h / 2.0);
			glVertex2f(0.0, h / 6.0);
			glVertex2f(2.0 * h / 6.0, - h / 2.0);
			glVertex2f(2.0 * h / 6.0, h / 6.0);
		glEnd();
		glBegin(GL_POINTS);
			glVertex2f(- 2.0 * h / 6.0, - h / 2.0);
			glVertex2f(2.0 * h / 6.0, - h / 2.0);
			glVertex2f(- 2.0 * h / 6.0, h / 6.0);
			glVertex2f(0.0, h / 6.0);
			glVertex2f(2.0 * h / 6.0, h / 6.0);
		glEnd();
	glEndList();
}

static void gen_sym_28_l_ru(FontLibrary * l)
{
	GLsizei h = l->h;
	glNewList(l->chars + 65 + 'û', GL_COMPILE);
		glLineWidth(h / 10.0);
		glPointSize(h / 10.0);
		glBegin(GL_LINES);
			glVertex2f(- 2.0 * h / 6.0, h / 6.0);
			glVertex2f(- 2.0 * h / 6.0, - h / 2.0);
			glVertex2f(2.0 * h / 6.0, h / 6.0);
			glVertex2f(2.0 * h / 6.0, - h / 2.0);
			glVertex2f(- 2.0 * h / 6.0, - h / 6.0);
			glVertex2f(- h / 6.0, - h / 6.0);
			glVertex2f(- 2.0 * h / 6.0, - h / 2.0);
			glVertex2f(- h / 6.0, - h / 2.0);
		glEnd();
		glBegin(GL_LINE_STRIP);
			for(GLsizei i = 0; i <= prec * h; i++)
				glVertex2f( - h / 6.0 + (h / 6.0) * sin(3.14 * i / (prec * h)),
						- 2.0 * h / 6.0 + (h / 6.0) * cos(3.14 * i / (prec * h)));
		glEnd();
		glBegin(GL_POINTS);
			glVertex2f(- 2.0 * h / 6.0, h / 6.0);
			glVertex2f(- 2.0 * h / 6.0, - h / 2.0);
			glVertex2f(2.0 * h / 6.0, h / 6.0);
			glVertex2f(2.0 * h / 6.0, - h / 2.0);
		glEnd();
	glEndList();
}

static void gen_sym_29_l_ru(FontLibrary * l)
{
	GLsizei h = l->h;
	glNewList(l->chars + 65 + 'ü', GL_COMPILE);
		glLineWidth(h / 10.0);
		glPointSize(h / 10.0);
		glBegin(GL_LINES);
			glVertex2f(- 2.0 * h / 6.0, h / 6.0);
			glVertex2f(- 2.0 * h / 6.0, - h / 2.0);
			glVertex2f(- 2.0 * h / 6.0, - h / 6.0);
			glVertex2f(h / 6.0, - h / 6.0);
			glVertex2f(- 2.0 * h / 6.0, - h / 2.0);
			glVertex2f(h / 6.0, - h / 2.0);
		glEnd();
		glBegin(GL_LINE_STRIP);
			for(GLsizei i = 0; i <= prec * h; i++)
				glVertex2f(h / 6.0 + (h / 6.0) * sin(3.14 * i / (prec * h)),
						- 2.0 * h / 6.0 + (h / 6.0) * cos(3.14 * i / (prec * h)));
		glEnd();
		glBegin(GL_POINTS);
			glVertex2f(- 2.0 * h / 6.0, h / 6.0);
			glVertex2f(- 2.0 * h / 6.0, - h / 2.0);
		glEnd();
	glEndList();
}

static void gen_sym_31_l_ru(FontLibrary * l)
{
	GLsizei h = l->h;
	glNewList(l->chars + 65 + 'þ', GL_COMPILE);
		glLineWidth(h / 10.0);
		glPointSize(h / 10.0);
		glBegin(GL_LINES);
			glVertex2f(- 2.0 * h / 6.0, h / 6.0);
			glVertex2f(- 2.0 * h / 6.0, - h / 2.0);
			glVertex2f(- 2.0 * h / 6.0, - h / 6.0);
			glVertex2f(0.0, - h / 6.0);
		glEnd();
		glBegin(GL_POINTS);
			glVertex2f(- 2.0 * h / 6.0, h / 6.0);
			glVertex2f(- 2.0 * h / 6.0, - h / 2.0);
		glEnd();
		glBegin(GL_LINE_STRIP);
			for(GLsizei i = 0; i <= prec * h; i++)
				glVertex2f(h / 6.0 + (h / 6.0) * cos(6.28 * i / (prec * h)),
						- h / 6.0 + (2.0 * h / 6.0) * sin(6.28 * i / (prec * h)));
		glEnd();
	glEndList();
}

static void gen_sym_32_l_ru(FontLibrary * l)
{
	GLsizei h = l->h;
	glNewList(l->chars + 65 + 'ÿ', GL_COMPILE);
		glLineWidth(h / 10.0);
		glPointSize(h / 10.0);
		glBegin(GL_LINES);
			glVertex2f(2.0 * h / 6.0, h / 6.0);
			glVertex2f(2.0 * h / 6.0, - h / 2.0);
			glVertex2f(2.0 * h / 6.0, h / 6.0);
			glVertex2f(- h / 6.0, h / 6.0);
			glVertex2f(2.0 * h / 6.0, - h / 6.0);
			glVertex2f(- h / 6.0, - h / 6.0);
			glVertex2f(2.0 * h / 6.0, - h / 6.0);
			glVertex2f(- 2.0 * h / 6.0, - h / 2.0);
		glEnd();
		glBegin(GL_POINTS);
			glVertex2f(2.0 * h / 6.0, h / 6.0);
			glVertex2f(2.0 * h / 6.0, - h / 2.0);
			glVertex2f(- 2.0 * h / 6.0, - h / 2.0);
		glEnd();
		glBegin(GL_LINE_STRIP);
			for(GLsizei i = 0; i <=  prec * h; i ++)
				glVertex2f( - h / 6.0 - (h / 6.0)*sin(3.15 * i / (prec * h)),
						   (h / 6.0) * cos(3.14 * i / (prec * h)));
		glEnd();
	glEndList();
}

static void gen_sym_0_num(FontLibrary * l)
{
	GLsizei h = l->h;
	glNewList(l->chars + 65 + '0', GL_COMPILE);
		glLineWidth(h / 10.0);
		glPointSize(h / 10.0);
		glBegin(GL_LINES);
			glVertex2f(- 2.0 * h / 6.0, h / 6.0);
			glVertex2f(- 2.0 * h / 6.0,  - h / 6.0);
			glVertex2f(2.0 * h / 6.0, h / 6.0);
			glVertex2f(2.0 * h / 6.0,  - h / 6.0);
			glVertex2f(2.0 * h / 6.0, h / 6.0);
			glVertex2f(- 2.0 * h / 6.0,  - h / 6.0);
		glEnd();
		glBegin(GL_LINE_STRIP);
			for(GLsizei i = 0; i <= prec * h; i ++)
				glVertex2f(0.0 + (2.0 * h / 6.0)*cos(3.14 * i / (prec * h)),
						   h / 6.0 + (2.0 * h / 6.0) * sin(3.14 * i / (prec * h)));
		glEnd();
		glBegin(GL_LINE_STRIP);
			for(GLsizei i = 0; i <=  prec * h; i ++)
				glVertex2f(0.0 + (2.0 * h / 6.0)*cos(3.14 * i / (prec * h)),
						   - h / 6.0 - (2.0 * h / 6.0) * sin(3.14 * i / (prec * h)));
		glEnd();
	glEndList();
}

static void gen_sym_1_num(FontLibrary * l)
{
	GLsizei h = l->h;
	glNewList(l->chars + 65 + '1', GL_COMPILE);
		glLineWidth(h / 10.0);
		glPointSize(h / 10.0);
		glBegin(GL_LINES);
			glVertex2f(h / 6.0, h / 2.0);
			glVertex2f(h / 6.0,  - h / 2.0);
			glVertex2f(h / 6.0, h / 2.0);
			glVertex2f(- h / 6.0, 0.0);
		glEnd();
		glBegin(GL_POINTS);
			glVertex2f(h / 6.0, h / 2.0);
			glVertex2f(h / 6.0,  - h / 2.0);
			glVertex2f(- h / 6.0, 0.0);
		glEnd();
	glEndList();
}

static void gen_sym_2_num(FontLibrary * l)
{
	GLsizei h = l->h;
	glNewList(l->chars + 65 + '2', GL_COMPILE);
		glLineWidth(h / 10.0);
		glPointSize(h / 10.0);
		glBegin(GL_LINES);
			glVertex2f(2.0 * h / 6.0, h / 6.0);
			glVertex2f(- 2.0 * h / 6.0,  - h / 2.0);
			glVertex2f(- 2.0 * h / 6.0,  - h / 2.0);
			glVertex2f(2.0 * h / 6.0,  - h / 2.0);
		glEnd();
		glBegin(GL_POINTS);
			glVertex2f(- 2.0 * h / 6.0,  - h / 2.0);
			glVertex2f(2.0 * h / 6.0,  - h / 2.0);
		glEnd();
		glBegin(GL_LINE_STRIP);
			for(GLsizei i = 0; i <= prec * h; i ++)
				glVertex2f((2.0 * h / 6.0)*cos(3.14 * i / (prec * h)),
						   h / 6.0 + (2.0 * h / 6.0) * sin(3.14 * i / (prec * h)));
		glEnd();
	glEndList();
}

static void gen_sym_3_num(FontLibrary * l)
{
	GLsizei h = l->h;
	glNewList(l->chars + 65 + '3', GL_COMPILE);
		glLineWidth(h / 10.0);
		glPointSize(h / 10.0);
		glBegin(GL_POINTS);
			glVertex2f(0.0, 0.0);
			glVertex2f(0.0, - h / 2.0);
			glVertex2f(0.0, h / 2.0);
		glEnd();
		glBegin(GL_LINE_STRIP);
			for(GLsizei i = - prec * h / 2; i <= prec * h / 2; i ++)
				glVertex2f((2.0 * h / 6.0)*cos(3.14 * i / (prec * h)),
						    h / 4.0 + (h / 4.0) * sin(3.14 * i / (prec * h)));
		glEnd();
		glBegin(GL_LINE_STRIP);
			for(GLsizei i =  - prec * h / 2; i <= prec * h / 2; i ++)
				glVertex2f((2.0 * h / 6.0)*cos(3.14 * i / (prec * h)),
							- h / 4.0 + (h / 4.0) * sin(3.14 * i / (prec * h)));
		glEnd();
	glEndList();
}

static void gen_sym_4_num(FontLibrary * l)
{
	GLsizei h = l->h;
	glNewList(l->chars + 65 + '4', GL_COMPILE);
		glLineWidth(h / 10.0);
		glPointSize(h / 10.0);
		glBegin(GL_LINES);
			glVertex2f(2.0 * h / 6.0, h / 2.0);
			glVertex2f(2.0 * h / 6.0, - h / 2.0);
			glVertex2f(- 2.0 * h / 6.0, 0.0);
			glVertex2f(2.0 * h / 6.0, 0.0);
			glVertex2f(0.0, h / 2.0);
			glVertex2f(- 2.0 * h / 6.0, 0.0);
		glEnd();
		glBegin(GL_POINTS);
			glVertex2f(2.0 * h / 6.0, h / 2.0);
			glVertex2f(2.0 * h / 6.0, - h / 2.0);
			glVertex2f(- 2.0 * h / 6.0, 0.0);
			glVertex2f(0.0, h / 2.0);
		glEnd();
	glEndList();
}

static void gen_sym_5_num(FontLibrary * l)
{
	GLsizei h = l->h;
	glNewList(l->chars + 65 + '5', GL_COMPILE);
		glLineWidth(h / 10.0);
		glPointSize(h / 10.0);
		glBegin(GL_LINES);
			glVertex2f(- 2.0 * h / 6.0, h / 2.0);
			glVertex2f(2.0 * h / 6.0, h / 2.0);
			glVertex2f(- 2.0 * h / 6.0, h / 2.0);
			glVertex2f(- 2.0 * h / 6.0, 0.0);
			glVertex2f(- 2.0 * h / 6.0, 0.0);
			glVertex2f(0.0, 0.0);
		glEnd();
		glBegin(GL_POINTS);
			glVertex2f(0.0, 0.0);
			glVertex2f(- 2.0 * h / 6.0, h / 2.0);
			glVertex2f(2.0 * h / 6.0, h / 2.0);
			glVertex2f(- 2.0 * h / 6.0, 0.0);
		glEnd();
		glBegin(GL_LINE_STRIP);
			for(GLsizei i = 0; i <= prec * h; i ++)
				glVertex2f((2.0 * h / 6.0) * sin(3.14 * i / (prec * h)),
							- h / 4.0 + (h / 4.0) * cos(3.14 * i / (prec * h)));
		glEnd();
	glEndList();
}

static void gen_sym_6_num(FontLibrary * l)
{
	GLsizei h = l->h;
	glNewList(l->chars + 65 + '6', GL_COMPILE);
		glLineWidth(h / 10.0);
		glPointSize(h / 10.0);
		glBegin(GL_LINES);
			glVertex2f(- 2.0 * h / 6.0, 2.0 * h / 6.0);
			glVertex2f(- 2.0 * h / 6.0,  - h / 4.0);
		glEnd();
		glBegin(GL_LINE_STRIP);
			for(GLsizei i = prec * h / 2; i <= prec * h; i ++)
				glVertex2f((2.0 * h / 6.0) * cos(3.14 * i / (prec * h)),
						   h / 6.0 + (2.0 * h / 6.0) * sin(3.14 * i / (prec * h)));
		glEnd();
		glBegin(GL_LINE_STRIP);
			for(GLsizei i = 0; i <= prec * h; i ++)
				glVertex2f((2.0 * h / 6.0)*cos(6.28 * i / (prec * h)),
							- h / 4.0 + (h / 4.0) * sin(6.28 * i / (prec * h)));
		glEnd();
	glEndList();
}

static void gen_sym_7_num(FontLibrary * l)
{
	GLsizei h = l->h;
	glNewList(l->chars + 65 + '7', GL_COMPILE);
		glLineWidth(h / 10.0);
		glPointSize(h / 10.0);
		glBegin(GL_LINES);
			glVertex2f(2.0 * h / 6.0, h / 2.0);
			glVertex2f(- 2.0 * h / 6.0, h / 2.0);
			glVertex2f(2.0 * h / 6.0, h / 2.0);
			glVertex2f(- 2.0 * h / 6.0, - h / 2.0);
			glVertex2f(- h / 6.0, 0.0);
			glVertex2f(h / 6.0, 0.0);
		glEnd();
		glBegin(GL_POINTS);
			glVertex2f(2.0 * h / 6.0, h / 2.0);
			glVertex2f(- 2.0 * h / 6.0, h / 2.0);
			glVertex2f(- 2.0 * h / 6.0, - h / 2.0);
			glVertex2f(- h / 6.0, 0.0);
			glVertex2f(h / 6.0, 0.0);
		glEnd();
	glEndList();
}

static void gen_sym_8_num(FontLibrary * l)
{
	GLsizei h = l->h;
	glNewList(l->chars + 65 + '8', GL_COMPILE);
		glLineWidth(h / 10.0);
		glPointSize(h / 10.0);
		glBegin(GL_LINE_STRIP);
			for(GLsizei i = 0; i <= prec * h; i ++)
				glVertex2f((2.0 * h / 6.0)*cos(6.28 * i / (prec * h)),
						    h / 4.0 + (h / 4.0) * sin(6.28 * i / (prec* h)));
		glEnd();
		glBegin(GL_LINE_STRIP);
			for(GLsizei i = 0; i <= prec * h; i ++)
				glVertex2f((2.0 * h / 6.0)*cos(6.28 * i / (prec * h)),
							- h / 4.0 + (h / 4.0) * sin(6.28 * i / (prec * h)));
		glEnd();
	glEndList();
}

static void gen_sym_9_num(FontLibrary * l)
{
	GLsizei h = l->h;
	glNewList(l->chars + 65 + '9', GL_COMPILE);
		glLineWidth(h / 10.0);
		glPointSize(h / 10.0);
		glBegin(GL_LINES);
			glVertex2f(2.0 * h / 6.0, h / 4.0);
			glVertex2f(2.0 * h / 6.0, - h / 4.0);
		glEnd();
		glBegin(GL_LINE_STRIP);
			for(GLsizei i = 0; i <= prec * h; i ++)
				glVertex2f((2.0 * h / 6.0)*cos(6.28 * i / (prec * h)),
						    h / 4.0 + (h / 4.0) * sin(6.28 * i / (prec * h)));
		glEnd();
		glBegin(GL_LINE_STRIP);
			for(GLsizei i = 3 * prec * h / 4.0; i <= prec * h; i ++)
				glVertex2f((2.0 * h / 6.0)*cos(6.28 * i / (prec * h)),
							- h / 4.0 + (h / 4.0) * sin(6.28 * i / (prec * h)));
		glEnd();
	glEndList();
}

static void gen_sym_1_syn(FontLibrary * l)
{
	GLsizei h = l->h;
	glNewList(l->chars + 65 + '-', GL_COMPILE);
		glLineWidth(h / 10.0);
		glPointSize(h / 10.0);
		glBegin(GL_LINES);
			glVertex2f(- h / 2.0, 0.0);
			glVertex2f(h / 2.0,  0.0);
		glEnd();
		glBegin(GL_POINTS);
			glVertex2f(- h / 2.0, 0.0);
			glVertex2f(h / 2.0,  0.0);
		glEnd();
	glEndList();
}

static void gen_sym_2_syn(FontLibrary * l)
{
	GLsizei h = l->h;
	glNewList(l->chars + 65 + '?', GL_COMPILE);
		glLineWidth(h / 10.0);
		glPointSize(h / 10.0);
		glBegin(GL_LINES);
			glVertex2f(- h / 6.0, 2.0 * h / 6.0);
			glVertex2f(h / 6.0, 2.0 * h / 6.0);
			glVertex2f(0.0, 0.0);
			glVertex2f(h / 6.0, 0.0);
			glVertex2f(0.0, 0.0);
			glVertex2f(0.0, - 2.0 * h / 6.0);
		glEnd();
		glBegin(GL_POINTS);
			glVertex2f(- h / 6.0, 2.0 * h / 6.0);
			glVertex2f(h / 6.0, 2.0 * h / 6.0);
			glVertex2f(0.0, 0.0);
			glVertex2f(0.0, - 2.0 * h / 6.0);
			glVertex2f(0.0, - h / 2.0);
		glEnd();
		glBegin(GL_LINE_STRIP);
			for(GLsizei i = 0; i <= prec * h; i ++)
				glVertex2f(h / 6.0 + (h / 6.0) * sin(3.14 * i / (prec * h)),
						    h / 6.0 + (h / 6.0) * cos(3.14 * i / (prec * h)));
		glEnd();
	glEndList();
}

FontLibrary * init_font(GLsizei h)
{
	prec = get_font_prec();
	FontLibrary * l = (FontLibrary *)malloc(sizeof(FontLibrary));
	l->h = h;
	l->chars = glGenLists(256);
	gen_sym_1_h_ru(l);
	gen_sym_2_h_ru(l);
	gen_sym_3_h_ru(l);
	gen_sym_5_h_ru(l);
	gen_sym_8_h_ru(l);
	gen_sym_11_h_ru(l);
	gen_sym_14_h_ru(l);
	gen_sym_15_h_ru(l);
	gen_sym_16_h_ru(l);
	gen_sym_17_h_ru(l);
	gen_sym_18_h_ru(l);
	gen_sym_19_h_ru(l);
	gen_sym_1_l_ru(l);
	gen_sym_2_l_ru(l);
	gen_sym_3_l_ru(l);
	gen_sym_4_l_ru(l);
	gen_sym_5_l_ru(l);
	gen_sym_6_l_ru(l);
	gen_sym_7_l_ru(l);
	gen_sym_8_l_ru(l);
	gen_sym_9_l_ru(l);
	gen_sym_10_l_ru(l);
	gen_sym_12_l_ru(l);
	gen_sym_11_l_ru(l);
	gen_sym_13_l_ru(l);
	gen_sym_14_l_ru(l);
	gen_sym_15_l_ru(l);
	gen_sym_17_l_ru(l);
	gen_sym_18_l_ru(l);
	gen_sym_19_l_ru(l);
	gen_sym_20_l_ru(l);
	gen_sym_21_l_ru(l);
	gen_sym_22_l_ru(l);
	gen_sym_24_l_ru(l);
	gen_sym_25_l_ru(l);
	gen_sym_28_l_ru(l);
	gen_sym_29_l_ru(l);
	gen_sym_31_l_ru(l);
	gen_sym_32_l_ru(l);
	gen_sym_0_num(l);
	gen_sym_1_num(l);
	gen_sym_2_num(l);
	gen_sym_3_num(l);
	gen_sym_4_num(l);
	gen_sym_5_num(l);
	gen_sym_6_num(l);
	gen_sym_7_num(l);
	gen_sym_8_num(l);
	gen_sym_9_num(l);
	gen_sym_1_syn(l);
	gen_sym_2_syn(l);
	return l;
}

void render_string(GLuint x, GLuint y, char * s, GLfloat ins, FontLibrary * l)
{
	glPushMatrix();
	GLsizei tex_len = strlen(s);
	GLfloat delta = l->h * (tex_len - 1) / 2.0;
	glTranslatef(x, y, 0);
	glColor4f(cr + 0.5 * ins,
			cg + 0.5 * ins,
			cb + 0.5 * ins, ca);
	glTranslatef(-delta, 0.0, 0.0);
	for(GLsizei i = 0; i < tex_len; i++)
	{
		glCallList(l->chars + 65 + s[i]);
		glTranslatef(l->h, 0.0, 0);
	}
	glPopMatrix();
}
