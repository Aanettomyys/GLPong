/*
 * drawing.c
 *
 *  Created on: 06.05.2010
 *      Author: cdev
 */

#include "games.h"

void draw_field()
{
    static GLuint field;
    if(field == 0)
    {
        field = glGenLists(1);
        glNewList(field, GL_COMPILE);
			glBegin(GL_QUADS);
				glColor4ub(3, 124, 61, 255);
				glVertex3f(-0.95f, -0.05f, -1.95f);
				glVertex3f(-0.95f, -0.05f, 1.95f);
				glVertex3f(-0.0125f, -0.05f, 1.95f);
				glVertex3f(-0.0125f, -0.05f, -1.95f);
				glVertex3f(0.0125f, -0.05f, -1.95f);
				glVertex3f(0.0125f, -0.05f, 1.95f);
				glVertex3f(0.95f, -0.05f, 1.95f);
				glVertex3f(0.95f, -0.05f, -1.95f);
				glColor4f(.7f, .7f, .7f, 1.0f);
				glVertex3f(-1.0f, -0.05f, -2.0f);
				glVertex3f(-1.0f, -0.05f, 2.0f);
				glVertex3f(-0.95f, -0.05f, 2.0f);
				glVertex3f(-0.95f, -0.05f, -2.0f);
				glVertex3f(0.95f, -0.05f, -2.0f);
				glVertex3f(0.95f, -0.05f, 2.0f);
				glVertex3f(1.0f, -0.05f, 2.0f);
				glVertex3f(1.0f, -0.05f, -2.0f);
				glVertex3f(-1.0f, -0.05f, -2.0f);
				glVertex3f(-1.0f, -0.05f, -1.95f);
				glVertex3f(1.0f, -0.05f, -1.95f);
				glVertex3f(1.0f, -0.05f, -2.0f);
				glVertex3f(-1.0f, -0.05f, 1.95f);
				glVertex3f(-1.0f, -0.05f, 2.0f);
				glVertex3f(1.0f, -0.05f, 2.0f);
				glVertex3f(1.0f, -0.05f, 1.95f);
				glVertex3f(-0.0125f, -0.05f, -2.0f);
				glVertex3f(-0.0125f, -0.05f, 2.0f);
				glVertex3f(0.0125f, -0.05f, 2.0f);
				glVertex3f(0.0125f, -0.05f, -2.0f);
			glEnd();
        glEndList();
    }
    glCallList(field);
}

void draw_racket(Racket * r)
{
    static GLuint racket;
    if(racket == 0)
    {
        racket = glGenLists(1);
        glNewList(racket, GL_COMPILE);
        glColor4ub(88, 10, 141, 200);
        glBegin(GL_QUADS);
        glVertex2f(-0.2f, 0.05f);
        glVertex2f(-0.2f, -0.05f);
        glVertex2f(0.2f, -0.05f);
        glVertex2f(0.2f, 0.05f);
        glEnd();
        glEndList();
    };
    glPushMatrix();
    glTranslatef(r->x, 0, r->z);
    glCallList(racket);
    glPopMatrix();
}

void draw_ball(Ball * b)
{
    glPushMatrix();
    glColor4f(.7f, .7f, .7f, 1.0f);
    glTranslatef(b->x, 0, b->z);
    GLUquadricObj * sphere = gluNewQuadric();
    gluSphere(sphere, 0.05f, 30, 30);
    gluDeleteQuadric(sphere);
    glPopMatrix();
}
