/*
 * main.c
 *
 *  Created on: 05.05.2010
 *      Author: cdev
 */

#include "games.h"

int main(int argc, char ** argv)
{
    init_glgame();
    game_loop();
    return (EXIT_SUCCESS);
}
