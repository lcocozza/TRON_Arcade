#include "TRON_Arcade.h"

void	get_host_list(SOCKET host_sock)
{
	char get[] = "GET Host List";
	
	if (send_net(host_sock, get) != -1)
	{
		recvfile_net("srcs/network/", host_sock);
	}
}
