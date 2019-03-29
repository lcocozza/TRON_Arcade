#include "TRON_Arcade.h"

void	init_server_screen(t_win *screen)
{
	char ref[] = "REFRESH";
	int i = 0;

	screen[0].border_w = newwin(LINES - 4, COLS / 3, 1, COLS / 3); //list
	screen[1].border_w = newwin(3, (COLS / 2) - (COLS / 4), LINES - 3, COLS / 3); //input
	screen[2].border_w = newwin(3, 15, LINES - 3, 111); //refresh

	while (i < NB_SLM)
	{
		box(screen[i].border_w, ACS_VLINE, ACS_HLINE);

		getmaxyx(screen[i].border_w, screen[i].max_y, screen[i].max_x);
		getbegyx(screen[i].border_w, screen[i].beg_y, screen[i].beg_x);

		screen[i].content_w = newwin(screen[i].max_y - 2, screen[i].max_x - 2, screen[i].beg_y + 1, screen[i].beg_x + 1);

		getmaxyx(screen[i].content_w, screen[i].max_y, screen[i].max_x);
		getbegyx(screen[i].content_w, screen[i].beg_y, screen[i].beg_x);

		screen[i].border_p = new_panel(screen[i].border_w);
		screen[i].content_p = new_panel(screen[i].content_w);

		top_panel(screen[i].content_p);
		i++;
	}
	wbkgd(screen[2].content_w, COLOR_PAIR(4));

	wattron(screen[2].content_w, A_BOLD | COLOR_PAIR(4));
	mvwaddstr(screen[2].content_w, screen[2].max_y / 2, ((screen[2].max_x - 1) / 2) - (strlen(ref) / 2), ref);
	wattroff(screen[2].content_w, A_BOLD | COLOR_PAIR(4));

	update_panels();
	doupdate();
}

void display_hlp(t_hlp *hlp, t_win *screen)
{
	werase(screen[0].content_w);
	mvwaddstr(screen[0].content_w, 0, 1, hlp[0].statut);
	wrefresh(screen[0].content_w);
}
