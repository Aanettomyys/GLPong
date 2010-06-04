/*
 * scoretable.c
 *
 *  Created on: 06.05.2010
 *      Author: cdev
 */

#include "games.h"
#include "widgets.h"
#include "interfaces.h"

static GLuint score_table[5] = { 0, 0, 0, 0, 0};

static void score_draw_interface()
{
	glCallList(score_frame->call_list);
	for(GLsizei i = 0; i < 5; i++)
		glw_score_show(score_s[i]);
	glw_button_show(score_clean);
	glw_button_show(score_ret);
}

static void score_event()
{
	SDL_Event event;
	while(SDL_PollEvent(&event))
	{
		if(event.type == SDL_MOUSEMOTION)
		{
			GLuint x = event.motion.x;
			GLuint y = global_context.screen_height - event.motion.y;
			glw_button_focus(score_clean, x, y);
			glw_button_focus(score_ret, x, y);
		}
		else if(event.type == SDL_MOUSEBUTTONDOWN)
		{
			glw_button_action(score_clean);
			glw_button_action(score_ret);
		}
	}
}

void switch_to_score()
{
	SDL_ShowCursor(1);
	global_context.draw_frame = NULL;
	global_context.draw_interface = score_draw_interface;
	global_context.next_frame = NULL;
	global_context.event_poller = score_event;
}

void clear_results_table()
{
	for(GLsizei i = 0; i < 5; i++)
		score_table[i] = 0;
}

GLuint * get_pointer_to_table()
{
	return &(score_table[0]);
}

void write_results_table()
{
    FILE * f = fopen(".scores", "w");
    if(f == NULL)
    {
        fprintf(stderr, "Scores: can't create or open table.\n");
        return;
    }
    for(GLsizei i = 0; i < 5; i++)
        fwrite(score_table + i, sizeof(unsigned long), 1, f);
    fclose(f);
}

void update_results_table(GLuint newscore)
{
    GLsizei pos = 0;
    while(pos < 5 && newscore < score_table[pos])
        pos++;
    for(GLsizei i = 4; i > pos; i--)
        score_table[i] = score_table[i - 1];
    if(pos < 5)
        score_table[pos] = newscore;
}

static int less(const void * f, const void * s)
{
	GLuint fi = *(GLuint *)f;
	GLuint se = *(GLuint *)s;
    if(fi > se)
        return -1;
    else if(fi < se)
        return 1;
    return 0;
}

void load_results_table()
{
    FILE * f = fopen(".scores", "r");
    if(f == NULL)
    {
        fprintf(stderr, "Scores: score.table not found.\n");
        return;
    }
    GLuint scor;
    for(GLsizei i = 0; i < 5 && fread(&scor, sizeof(GLuint), 1, f); i++)
        score_table[i] = scor;
    qsort(score_table, 5, sizeof(GLuint), less);
    fclose(f);
}
