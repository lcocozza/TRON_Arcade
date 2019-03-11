#include "TRON_Arcade.h"

void	splash_title(void)
{
	char subtitle[] = "A  R  C  A  D  E";
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
	attron(COLOR_PAIR(2));
	mvprintw(y + 2, (COLS / 2) - (strlen(subtitle) / 2), "%s", subtitle);
	attroff(COLOR_PAIR(2));

	fclose(title);
}

void	splash_screen(void)
{	
	int i = 0;
	int g = 0;
	int b = 0;
	
	init_color(COLOR_BLACK, 23, 23, 23);
	init_pair(0, COLOR_BLACK, COLOR_BLACK);
	bkgd(COLOR_PAIR(0));

	while (i++ < 100)
	{
		init_color(COLOR_CYAN, 0 , g, b);
		init_pair(1, COLOR_CYAN, COLOR_CYAN);
		init_pair(2, COLOR_CYAN, COLOR_BLACK);
		splash_title();
		refresh();
		g += 10;
		b += 10;
		msleep(100);
	}
	getch();
}
