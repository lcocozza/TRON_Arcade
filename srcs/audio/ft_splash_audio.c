#include "TRON_Arcade.h"

FMOD_SOUND	*play_splash_theme(FMOD_SYSTEM *system)
{
	FMOD_SOUND *theme = NULL;
	if (FMOD_System_CreateSound(system, "audio/music/TRON_8-Bit_GRID.ogg", FMOD_CREATESTREAM, 0, &theme) != FMOD_OK)
		end_audio(system, "FMOD system can't create sound\n", EXIT_FAILURE);

	if (FMOD_System_PlaySound(system, theme, FMOD_CHANNELORDER_DEFAULT, 0, NULL) != FMOD_OK)
	{
		FMOD_Sound_Release(theme);
		end_audio(system, "FMOD system can't play sound\n", EXIT_FAILURE);
	}
	return theme;
}
