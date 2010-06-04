/*
 * ball.c
 *
 *  Created on: 06.05.2010
 *      Author: cdev
 */

#include "games.h"

Ball * make_ball()
{
    Ball * b = (Ball *)malloc(sizeof(Ball));
    b->x = 0.0f;
    b->z = 1.8f;
    b->vx = 0.0f;
    b->vz = - 0.08f;
    return b;
}

void ball_wall_reflect(Ball * b)
{
    if(fabs(b->x) >= 1.0f)
        b->vx = - b->vx;
    if(b->x >= 1.0f)
        b->x = 1.0f;
    if(b->x <= - 1.0f)
        b->x = - 1.0f;
}

void ball_normalize_speed(Ball * b)
{
    if(fabs(b->vz) > 0.1f)
        b->vz = ((b->vz >= 0)? 1 : -1) * 0.1f;
    if(fabs(b->vx) > 0.06)
        b->vx = ((b->vx >= 0)? 1 : -1) * 0.06f;
    if(fabs(b->vz) < 0.06f)
        b->vz = ((b->vz >= 0)? 1 : -1) * 0.06f;
}
