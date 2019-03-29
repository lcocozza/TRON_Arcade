#include "TRON_Arcade.h"

void	init_screen(void)
{
	if (initscr() == NULL)
		end_prog("Ncurses can't initialize\n", EXIT_FAILURE);
	if (has_colors() == FALSE)
		end_screen("Terminal does not support color\n", EXIT_FAILURE);
	if (start_color() == ERR)
		end_screen("Color can't start\n", EXIT_FAILURE);
}

void	end_screen(char *str, short int exit_type)
{
	endwin();
	end_prog(str, exit_type);
}

int	screen_size(void)
{
	char wrong[] = "WRONG SIZE.";
	char explain[] = "Please, restart program in full-screen.";
	char quit[] = "Press 'q' to quit.";
	int b = 0;

	if (LINES < 42 || COLS < 191)
	{
		noecho();
		init_pair(5, COLOR_WHITE, COLOR_RED);
		bkgd(COLOR_PAIR(5));
		b = -1;

		do
		{
			erase();
			attron(A_BOLD);
			mvprintw(LINES / 2, (COLS / 2) - (strlen(wrong) / 2), "%s", wrong);
			mvprintw((LINES / 2) + 1, (COLS / 2) - (strlen(explain) / 2), "%s", explain);
			mvprintw(LINES - 1, COLS - strlen(quit), "%s", quit);
			attroff(A_BOLD);
			mvaddstr(1, 1, "minimum required: 42 lines, 191 columns");
			mvprintw(2, 1, "actual: %d lines, %d columns", LINES, COLS);
			refresh();
		}
		while (getch() != 'q') ;
		erase();
	}
	else
		resizeterm(42, 191);
	return b;
}

void hl_log(t_win *screen, char *str)
{
	werase(screen[0].content_w);

	wattron(screen[0].content_w, A_DIM | A_ITALIC);
	mvwaddstr(screen[0].content_w, 0, 1, str);
	wattroff(screen[0].content_w, A_DIM | A_ITALIC);

	wrefresh(screen[0].content_w);
}
