#include "TRON_Arcade.h"

void	get_host_list(SOCKET host_sock)
{
	char get[] = "GET Host List";
	
	printf("send_net start\n");
	if (send_net(host_sock, get) != -1)
	{
		printf("send_net end\n");
		//recvfile_net("srcs/network/", host_sock);
	}
}
