/*
 * interfaces.h
 *
 *  Created on: 22.05.2010
 *      Author: cdev
 */

#ifndef INTERFACES_H_
#define INTERFACES_H_

#include "widgets.h"

extern GLWButton * menu_single_button;
extern GLWButton * menu_multi_button;
extern GLWButton * menu_score_button;
extern GLWButton * menu_settings_button;
extern GLWButton * menu_exit_button;
extern GLWChooser * test;

extern GLWScoreView * single_score;
extern GLWMenu * single_menu;
extern GLWModalDialog * single_dialog;
void single_release();
void single_new();
void single_continue();

extern GLWScoreView * multi_first_score;
extern GLWScoreView * multi_second_score;
extern GLWMenu * multi_menu;
extern GLWModalDialog * multi_dialog;
void multi_release();
void multi_continue();
void multi_new();

extern GLWScore * score_s[5];
extern GLWFrame * score_frame;
extern GLWButton * score_clean;
extern GLWButton * score_ret;
void clear_results_table();
void load_results_table();
void write_results_table();
void update_results_table(GLuint);
GLuint * get_pointer_to_table();

extern GLWChooser * settings_fsaa;
extern GLWChooser * settings_font;
extern GLWChooser * settings_mmax;
extern GLWButton * settings_ret;
void load_settings();
void init_settings();
void write_settings();
GLuint get_fsaa();
GLfloat get_font_prec();
GLsizei get_mmax();

#endif /* INTERFACES_H_ */
