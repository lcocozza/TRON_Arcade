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

void	splash_screen(void)
{	
	int i = 0;
	int g = 0;
	int b = 0;

	curs_set(0);
	init_color(COLOR_BLACK, 23, 23, 23);
	init_pair(0, COLOR_BLACK, COLOR_BLACK);
	init_pair(2, COLOR_CYAN, COLOR_BLACK);
	init_pair(3, COLOR_WHITE, COLOR_WHITE);
	bkgd(COLOR_PAIR(0));

	while (i++ < 100)
	{
		init_color(COLOR_CYAN, 0 , g, b);
		init_pair(1, COLOR_CYAN, COLOR_CYAN);
		splash_title();
		g += 10;
		b += 10;
		msleep(75);
	}
	splash_subtitle();
	getch();
}
