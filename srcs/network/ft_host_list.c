#include "TRON_Arcade.h"

void	get_host_list(t_win *screen)
{
	SOCKET host_sock;
	char get[] = "GET Host List";

	hl_log(screen, "Trying connect host list server...");
	if ((host_sock = host_connect(HL_IP, HL_PORT)) != -1)
	{
		hl_log(screen, "Getting host list...");
		if (send_net(host_sock, get) != -1)
			recvfile_net("srcs/network/", host_sock);
		else
			hl_log(screen, "Can't get host list.");
	}
	else
		hl_log(screen, "Can't connect host list server.");
}

int	count_nb_host(void)
{
	FILE *host_file = NULL;
	char c;
	int i = 1;

	host_file = fopen("srcs/network/.host_list.tron", "r");
	while ((c = fgetc(host_file)) != EOF)
	{
		if (c == '\n')
		i++;
	}

	fclose(host_file);
	return i;
}

void get_host_info(t_hlp *hlp)
{
	char get[] = "GET Host Info";
	FILE *host_file = NULL;
	char *buffer = NULL;
	SOCKET host_sock;
	int slot = 1;
	int page = 1;
	int i = 0;

	host_file = fopen("srcs/network/.host_list.tron", "r");
	buffer = malloc(sizeof(char) * 1);

	while (get_next_line(host_file, &buffer) > 0)
	{
		hlp[i].host_ip = malloc(sizeof(char) * strlen(buffer));
		strcpy(hlp[i].host_ip, buffer);
		if ((host_sock = host_connect(hlp[i].host_ip, H_PORT)) == -1)
		{
			strcpy(hlp[i].statut, "Disconnected");
			hlp[i].j_act = 0;
			hlp[i].j_max = 0;
		}
		else
		{
			send_net(host_sock, get);
			strcpy(hlp[i].statut, recv_net(host_sock));
			hlp[i].j_act = atoi(recv_net(host_sock));
			hlp[i].j_max = atoi(recv_net(host_sock));
		}
		hlp[i].slot = slot++;
		hlp[i].page = page;

		if (slot > 9)
		{
			slot = 1;
			page++;
		}

		close(host_sock);
		i++;
	}

	fclose(host_file);
}
