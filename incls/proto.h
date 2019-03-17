#ifndef PROTO_H
#define PROTO_H

/****************/
/*	srcs/	*/
/****************/
/*ft_general.c*/
void	end_all(FMOD_SYSTEM *system, char *str, short int exit_type);
void	end_prog(char *str, short int exit_type);
int	launch_splash(FMOD_SYSTEM *system);
void	launch_solo(void);
void	launch_multi(void);

/************************/
/*	srcs/screen/	*/
/************************/
/*ft_general_screen.c*/
void	init_screen(void);
void	end_screen(char *str, short int exit_type);
int	screen_size(void);
/*ft_splash_screen.c*/
void	splash_title(void);
void	splash_subtitle(void);
int	splash_menu(FMOD_SYSTEM *system);
void	splash_screen(void);

/************************/
/*	srcs/audio/	*/
/************************/
/*ft_general_audio.c*/
void	end_audio(FMOD_SYSTEM *system, char *str, short int exit_type);
FMOD_SYSTEM	*init_audio(void);
/*ft_splash_audio.c*/
FMOD_SOUND	*play_splash_theme(FMOD_SYSTEM *system);
FMOD_SOUND	*play_menu_select(FMOD_SYSTEM *system);
FMOD_SOUND	*play_menu_move(FMOD_SYSTEM *system);

#endif
