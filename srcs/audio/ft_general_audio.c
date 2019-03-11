#include "TRON_Arcade.h"

void	end_audio(FMOD_SYSTEM *system, char *str, short int exit_type)
{
	FMOD_System_Close(system);
	FMOD_System_Release(system);
	end_prog(str, exit_type);
}

FMOD_SYSTEM	*init_audio(void)
{
	FMOD_SYSTEM *system;
	if (FMOD_System_Create(&system) != FMOD_OK)
		end_prog("FMOD system can't be created\n", EXIT_FAILURE);
	if (FMOD_System_Init(system, 32, FMOD_INIT_NORMAL, FMOD_OUTPUTTYPE_AUTODETECT) != FMOD_OK)
		end_audio(system, "FMOD system can't be init\n", EXIT_FAILURE);
	return system;
}
