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
