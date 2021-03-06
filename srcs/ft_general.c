#include "TRON_Arcade.h"

void	end_all(SOCKET socket, FMOD_SYSTEM *system, char *str, short int exit_type)
{
	if (socket != NO_SOCK)
		end_network(socket, NULL, NO_EXIT);
	if (system != NULL)
		end_audio(system, NULL, NO_EXIT);
	end_screen(NULL, NO_EXIT);
	end_prog(str, exit_type);
}

void	end_prog(char *str, short int exit_type)
{
	if (str != NULL)
		printf("%s", str);
	if (exit_type != NO_EXIT)
		exit(exit_type);
}

int	launch_splash(FMOD_SYSTEM *system)
{
	FMOD_SOUND *splash_theme;
	int menu = 0;

	splash_theme = play_splash_theme(system);
	splash_screen();
	menu = splash_menu(system);
	FMOD_Sound_Release(splash_theme);
	return menu;
}

void	launch_solo(void)
{

}

void	launch_multi(void)
{
	t_hlp *hlp = NULL;
	t_win screen[3];

	hlp = malloc(sizeof(t_hlp) * count_nb_host());

	init_server_screen(screen);
	get_host_list(screen);
	get_host_info(hlp);
	display_hlp(hlp, screen);
	getch();
}
