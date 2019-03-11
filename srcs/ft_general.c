#include "TRON_Arcade.h"

void	end_all(FMOD_SYSTEM *system, char *str, short int exit_type)
{
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
