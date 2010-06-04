/*
 * racket.c
 *
 *  Created on: 06.05.2010
 *      Author: cdev
 */

#include "games.h"

void collide_with_ball(Racket * r, Ball * b)
{
    GLfloat step_z = 0.01f * b->vz;
    GLfloat rx = r->x + ((r->rvx + r->lvx) / 2.0f);
    GLfloat z_pos = b->z;
    GLfloat step_x = 0.01f * b->vx;
    GLfloat x_pos = b->x;
    while(fabs(z_pos - b->z - b->vz) >= fabs(step_z))
    {
        if((0.0025 - (r->z - z_pos) * (r->z- z_pos) >= 0) &&
                ((fabs(-sqrt(0.0025 - (r->z - z_pos) * (r->z- z_pos)) + x_pos - rx) <= 0.2f) ||
                 (fabs(sqrt(0.0025f - (r->z - z_pos) * (r->z - z_pos)) + x_pos - rx) <= 0.2f)))
        {
            b->z = r->z + ((b->vz >= 0)? - 0.1f : 0.1f);
            b->vz = - ((r->lvx + r->rvx == 0)? b->vz * 0.95f : b->vz * 1.05f);
            b->vx = b->vx + r->lvx + r->rvx;
            return;
        }
        z_pos += step_z;
        x_pos += step_x;
    }
}

Racket * make_racket(GLfloat cx, GLfloat cz)
{
    Racket * r = (Racket *)malloc(sizeof(Racket));
    r->x = cx;
    r->z = cz;
    r->lvx = 0.0f;
    r->rvx = 0.0f;
    return r;
}

void racket_wall(Racket * r)
{
    if(r->x >= 0.8f)
        r->rvx = 0.0f;
    if(r->x <= - 0.8f)
        r->lvx = 0.0f;
}
