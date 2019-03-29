#ifndef STRUCT_H
#define STRUCT_H

typedef struct sockaddr_in SOCKADDR_IN;
typedef struct sockaddr SOCKADDR;
typedef struct in_addr IN_ADDR;
typedef int SOCKET;

typedef struct s_win
{
	WINDOW *border_w;
	WINDOW *content_w;
	PANEL *border_p;
	PANEL *content_p;
	int max_y;
	int max_x;
	int beg_y;
	int beg_x;
} t_win;

typedef struct s_hlp
{
	WINDOW *content_w;
	PANEL *content_p;
	char statut[15];
	char *host_ip;
	int j_act;
	int j_max;
	int slot;
	int page;
}	t_hlp;

#endif
