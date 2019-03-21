#include "TRON_Arcade.h"

int	main(void)
{
/*	FMOD_SYSTEM *system;
	int menu = 0;

	system = init_audio();
	init_screen();
	if (screen_size() == -1)
		end_all(NO_SOCK, system, NULL, EXIT_FAILURE);
	menu = launch_splash(system);
	if (menu == 0)
		launch_solo();
	else if (menu == 1)
		launch_multi();
	end_all(NO_SOCK, system, NULL, EXIT_SUCCESS);
*/
	launch_multi();
	return 0;
}
