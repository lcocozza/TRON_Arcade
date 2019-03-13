#include "TRON_Arcade.h"

int	main(void)
{
	FMOD_SYSTEM *system;

	system = init_audio();
	init_screen();
	launch_splash(system);
	end_all(system, NULL, EXIT_SUCCESS);
	return 0;
}
