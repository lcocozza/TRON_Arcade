#include "TRON_Arcade.h"

void	splash_title(void)
{
	FILE *title = NULL;
	int x, y;
	int c;
	int p;

	title = fopen("srcs/screen/.TITLE.tron", "r");
	if (title == NULL)
		end_screen("Can't open TITLE.tron\n", EXIT_FAILURE);
	x = (COLS / 2) - 40;
	y = (LINES / 2) - 15;

	while ((c = fgetc(title)) != EOF)
	{
		p = ((c == '#') ? 1 : 0);
		mvaddch(y, x, c | COLOR_PAIR(p));
		x++;
		if (c == '\n')
		{
			y++;
			x = (COLS / 2) - 40;
		}
	}
	fclose(title);
	refresh();
}

void	splash_subtitle(void)
{
	char subtitle[] = "          A  R  C  A  D  E          ";
	int i = 0;
	int j = 0;

	while (j < (int)strlen(subtitle) * 2)
	{
		mvaddch((LINES / 2) - 3, (COLS / 2) - (strlen(subtitle) / 2) + i, subtitle[i] | COLOR_PAIR((j < (int)strlen(subtitle)) ? 3 : 2) | A_BOLD);
		refresh();
		msleep(3);
		if (i == (int)strlen(subtitle) - 1)
			i = 0;
		else
			i++;
		j++;
	}
}

int	splash_menu(FMOD_SYSTEM *system) 
{
	FMOD_SOUND *move;
	char solo[] = "Solo";
	char multi[] = "Multiplayer";
	char quit[] = "Press 'q' to quit.";
	int b = 0;
	int c = 0;
	
	while (c != 'q' && c != 10 && c != ' ')
	{
		attron(A_BOLD);
		if (!(b))
			attron(A_REVERSE);
		mvprintw((LINES / 2) + 3, (COLS / 2) - (strlen(solo) / 2), "%s", solo);
		if (!(b))
			attroff(A_REVERSE);
		else
			attron(A_REVERSE);
		mvprintw((LINES / 2) + 5, (COLS / 2) - (strlen(multi) / 2), "%s", multi);
		if (b)
			attroff(A_REVERSE);
		mvprintw(LINES - 1, (COLS - 1) - strlen(quit), "%s", quit);
		attroff(A_BOLD);
		refresh();
		c = getch();
		if (c == KEY_UP && b)
		{
			b = 0;
			move = play_menu_move(system);
		}
		else if (c == KEY_DOWN && !(b))
		{
			b = 1;
			move = play_menu_move(system);
		}
		else if (c == 9)
		{
			b = ((b) ? 0 : 1);
			move = play_menu_move(system);
		}
	}
	FMOD_Sound_Release(move);
	return ((c == 'q') ? -1 : b);
}

void	splash_screen(void)
{
	int i = 0;
	int green = 0;
	int blue = 0;

	curs_set(0);
	noecho();
	keypad(stdscr, TRUE);
	init_color(COLOR_BLACK, 0, 0, 0);
	init_pair(0, COLOR_WHITE, COLOR_BLACK);
	init_pair(2, COLOR_CYAN, COLOR_BLACK);
	init_pair(3, COLOR_WHITE, COLOR_WHITE);
	init_pair(4, COLOR_WHITE, COLOR_BLACK);
	bkgd(COLOR_PAIR(0));

	while (i++ < 100)
	{
		init_color(COLOR_CYAN, 0 , green, blue);
		init_pair(1, COLOR_CYAN, COLOR_CYAN);
		splash_title();
		green += 10;
		blue += 10;
		msleep(75);
	}
	splash_subtitle();
}
