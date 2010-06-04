/*
 * widgetfactory.c
 *
 *  Created on: 21.05.2010
 *      Author: cdev
 */
#include "widgets.h"
#include "games.h"
#include "interfaces.h"

static void make_menu_interface()
{
	menu_single_button = glw_button_make(global_context.screen_width / 2,
			5 * global_context.screen_height / 9, 0.3, "Одиночная", switch_to_single);
	menu_multi_button = glw_button_make(global_context.screen_width / 2,
			4 * global_context.screen_height / 9, 0.3, "Вдвоем", switch_to_multi);
	menu_score_button = glw_button_make(global_context.screen_width / 2,
			3 * global_context.screen_height / 9, 0.3, "Рейтинг", switch_to_score);
	menu_settings_button = glw_button_make(global_context.screen_width / 2,
			2 * global_context.screen_height / 9, 0.3, "Настройки", switch_to_settings);
	menu_exit_button = glw_button_make(global_context.screen_width / 2,
			global_context.screen_height / 9, 0.3, "Выход", halt_game);
}

static void make_single_inerface()
{
	char * captions[] = { "Заново", "Продолжить", "В меню", "Выход" };
	glw_action hndls[] = { single_new, single_continue, switch_to_menu, halt_game };
	single_score = glw_scoreview_make(global_context.screen_width / 4,
			8 * global_context.screen_height / 9, 0.3);
	single_dialog = glw_modaldialog_make(global_context.screen_width / 2,
			global_context.screen_height / 2, 0.3, 0.3,
			"Начать заново?", "Да", "Нет", single_new, single_release);
	single_menu = glw_menu_make(global_context.screen_width / 2,
			global_context.screen_height / 2, 4,
			captions, hndls);
}

static void make_multi_interface()
{
	char * captions[] = { "Заново", "Продолжить", "В меню", "Выход" };
	glw_action hndls[] = { multi_new, multi_continue, switch_to_menu, halt_game };
	multi_first_score = glw_scoreview_make(global_context.screen_width / 4,
			8 * global_context.screen_height / 9, 0.3);
	multi_second_score = glw_scoreview_make(3 * global_context.screen_width / 4,
			8 * global_context.screen_height / 9, 0.3);
	multi_dialog = glw_modaldialog_make(global_context.screen_width / 2,
			global_context.screen_height / 2, 0.3, 0.3,
			"Начать заново?", "Да", "Нет", multi_new, multi_release);
	multi_menu = glw_menu_make(global_context.screen_width / 2,
			global_context.screen_height / 2, 4,
			captions, hndls);
}

static void make_score_interface()
{
	GLuint * head = get_pointer_to_table();
	score_frame = glw_frame_make(global_context.screen_width / 2,
			global_context.screen_height / 2,
			border * 6 + text->h * 10,
			border * 14 + text->h * 5, 0.3);
	score_ret = glw_button_make(3 * global_context.screen_width / 4,
			global_context.screen_height / 9,
			0.3, "Вернуться", switch_to_menu);
	score_clean = glw_button_make(global_context.screen_width / 4,
			 global_context.screen_height / 9,
			0.3, "Очистить", clear_results_table);
	GLuint h = score_frame->cy + score_frame->height / 2 - border - text->h / 2;
	for(GLsizei i = 0; i < 5; i ++)
	{
		score_s[i] = glw_score_make(global_context.screen_width / 2,
				h, 0.3, head + i);
		h -= 3 * border + text->h;
	}
}

static void make_settings_interface()
{
	char * fsaa_cap[] = { "Отключено", "х2", "х4", "х6"};
	char * mmax_cap[] = { "3", "7", "10", "Нет"};
	char * font_cap[] = { "Низкое", "Среднее", "Высокое"};
	GLuint * fsaaps[] = { fsaa, fsaa + 1, fsaa + 2, fsaa + 3};
	GLfloat * fontps[] = { font_prec, font_prec + 1, font_prec + 2};
	GLsizei * mmaxps[] = { mmax_ball, mmax_ball + 1, mmax_ball + 2, mmax_ball + 3};
	settings_ret = glw_button_make(3 * global_context.screen_width / 4,
			global_context.screen_height / 8, 0.3, "Вернуться", switch_to_menu);
	settings_fsaa = glw_chooser_make(global_context.screen_width / 4,
			3 * global_context.screen_height / 4, 4, 0.3,
			"Сглаживание", fsaa_cap, fsaaps);
	settings_font = glw_chooser_make(global_context.screen_width / 4,
			2 * global_context.screen_height / 4, 3, 0.3,
			"Качество шрифта", font_cap, fontps);
	settings_mmax = glw_chooser_make(global_context.screen_width / 4,
			global_context.screen_height / 4, 4, 0.3, "Побед",
			mmax_cap, mmaxps);
}

void init_factory()
{
	border = global_context.screen_height / 50;
	text = init_font(global_context.screen_height / 30);
	make_menu_interface();
	make_single_inerface();
	make_multi_interface();
	make_score_interface();
	make_settings_interface();
}
