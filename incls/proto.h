#ifndef PROTO_H
#define PROTO_H

/**********/
/*	srcs/	*/
/**********/
/*ft_general.c*/
void	end_all(SOCKET socket, FMOD_SYSTEM *system, char *str, short int exit_type);
void	end_prog(char *str, short int exit_type);
int	launch_splash(FMOD_SYSTEM *system);
void	launch_solo(void);
void	launch_multi(void);
/*libft.c*/
int	get_next_line(FILE *fd, char **line);
char	*ft_itoa(int n);

/******************/
/*	srcs/screen/	*/
/******************/
/*ft_general_screen.c*/
void	init_screen(void);
void	end_screen(char *str, short int exit_type);
int	screen_size(void);
void hl_log(t_win *screen, char *str);
/*ft_splash_screen.c*/
void	splash_title(void);
void	splash_subtitle(void);
int	splash_menu(FMOD_SYSTEM *system);
void	splash_screen(void);
/*ft_server_screen.c*/
void init_server_screen(t_win *screen);
void display_hlp(t_hlp *hlp, t_win *screen);

/****************/
/*	srcs/audio/	*/
/****************/
/*ft_general_audio.c*/
void	end_audio(FMOD_SYSTEM *system, char *str, short int exit_type);
FMOD_SYSTEM	*init_audio(void);
/*ft_splash_audio.c*/
FMOD_SOUND	*play_splash_theme(FMOD_SYSTEM *system);
FMOD_SOUND	*play_menu_select(FMOD_SYSTEM *system);
FMOD_SOUND	*play_menu_move(FMOD_SYSTEM *system);

/******************/
/*	srcs/network/	*/
/******************/
/*ft_general_network.c*/
void	end_network(SOCKET socket, char *str, short int exit_type);
int	host_connect(const char *hostname, short unsigned int port);
int	recvfile_net(const char *path, SOCKET socket);
int	send_net(SOCKET socket, const char *buffer);
char	*recv_net(SOCKET socket);
/*ft_host_list.c*/
void	get_host_list(t_win *screen);
int	count_nb_host(void);
void get_host_info(t_hlp *hlp);

#endif
