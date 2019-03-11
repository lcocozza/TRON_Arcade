#include "TRON_Arcade.h"

int	main()
{
	FMOD_SYSTEM *system;
	FMOD_SOUND *splash_theme;

	system = init_audio();
	init_screen();
	splash_theme = play_splash_theme(system);
	splash_screen();
	FMOD_Sound_Release(splash_theme);
	end_all(system, NULL, EXIT_SUCCESS);
	return 0;
}
