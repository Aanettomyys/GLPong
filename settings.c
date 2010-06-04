/*
 * settings.c
 *
 *  Created on: 23.05.2010
 *      Author: cdev
 */

#include "games.h"
#include "widgets.h"
#include "interfaces.h"

static GLsizei bmmax = 3;
static GLuint bfsaa = 2;
static GLfloat bfont = 4.0;

static void settings_draw_interface()
{
	glw_chooser_show(settings_fsaa);
	glw_chooser_show(settings_font);
	glw_chooser_show(settings_mmax);
	glw_button_show(settings_ret);
}

static void settings_event()
{
	SDL_Event event;
	while(SDL_PollEvent(&event))
	{
		GLuint x = event.motion.x;
		GLuint y = global_context.screen_height - event.motion.y;
		if(event.type == SDL_MOUSEMOTION)
		{
			if(glw_chooser_focus(settings_fsaa, x, y));
			else if(glw_chooser_focus(settings_font, x, y));
			else if(glw_chooser_focus(settings_mmax, x, y));
			else
				glw_button_focus(settings_ret, x, y);
		}
		else if(event.type == SDL_MOUSEBUTTONDOWN)
		{
			glw_button_action(settings_ret);
			glw_chooser_action(settings_font, x, y);
			glw_chooser_action(settings_fsaa, x, y);
			glw_chooser_action(settings_mmax, x, y);
		}
	}
}

void switch_to_settings()
{
	SDL_ShowCursor(1);
	global_context.draw_frame = NULL;
	global_context.draw_interface = settings_draw_interface;
	global_context.event_poller = settings_event;
	global_context.next_frame = NULL;
}

void load_settings()
{
    FILE * f = fopen(".ss", "r");
    if(f == NULL)
        return;
    GLuint bmagic = 0;
    fread(&bmagic, sizeof(GLuint), 1, f);
    if(bmagic == settings_magic)
    {
    	fread(&bfont, sizeof(GLfloat), 1, f);
    	fread(&bfsaa, sizeof(GLuint), 1, f);
    	fread(&bmmax, sizeof(GLsizei), 1, f);

    }
    fclose(f);
}

void write_settings()
{
    FILE * f = fopen(".ss", "w");
    if(f == NULL)
        return;
    fwrite(&settings_magic, sizeof(GLuint), 1, f);
    fwrite(settings_font->current->val, sizeof(GLfloat), 1, f);
    fwrite(settings_fsaa->current->val, sizeof(GLuint), 1, f);
    fwrite(settings_mmax->current->val, sizeof(GLsizei), 1, f);
    fclose(f);
}

void init_settings()
{
	for(GLsizei i = 0; i < settings_font->size; i++)
	    if(*((GLfloat *)(settings_font->figures[i]->val)) == bfont)
	    {
	    	settings_font->current->text = settings_font->figures[i]->text;
	    	settings_font->current->val = settings_font->figures[i]->val;
	    	break;
	    }
	for(GLsizei i = 0; i < settings_fsaa->size; i++)
	    if(*((GLuint *)(settings_fsaa->figures[i]->val)) == bfsaa)
	    {
	    	settings_fsaa->current->text = settings_fsaa->figures[i]->text;
	    	settings_fsaa->current->val = settings_fsaa->figures[i]->val;
	    	break;
	    }
	for(GLsizei i = 0; i < settings_mmax->size; i++)
		if(*((GLsizei *)(settings_mmax->figures[i]->val)) == bmmax)
		{
			settings_mmax->current->text = settings_mmax->figures[i]->text;
			settings_mmax->current->val = settings_mmax->figures[i]->val;
			break;
		}
}

GLuint get_fsaa()
{
	GLuint * pfsaa = (settings_fsaa != NULL)?
			(GLuint *)(settings_fsaa->current->val) : &bfsaa;
	return *pfsaa;
}

GLfloat get_font_prec()
{
	GLfloat * pfp = (settings_font != NULL)?
			(GLfloat *)(settings_font->current->val) : &bfont;
	return *pfp;
}

GLsizei get_mmax()
{
	GLsizei * pmmax = (settings_mmax != NULL)?
			(GLsizei *)(settings_mmax->current->val) : &bmmax;
	return *pmmax;
}
