#include "TRON_Arcade.h"

void	end_network(SOCKET socket, char *str, short int exit_type)
{
	close(socket);
	end_prog(str, exit_type);
}

int	host_connect(const char *hostname, short unsigned int port)
{
	struct hostent *host = NULL;
	SOCKADDR_IN host_in = {0};
	SOCKET host_sock;

	if ((host_sock = socket(AF_INET, SOCK_STREAM, 0)) == -1)
		return -1;
	if ((host = gethostbyname(hostname)) == NULL)
		return -1;

	host_in.sin_addr = *(IN_ADDR *)host->h_addr;
	host_in.sin_port = htons(port);
	host_in.sin_family = AF_INET;

	if (connect(host_sock, (SOCKADDR *)&host_in, sizeof(SOCKADDR)) == -1)
		return -1;
	return host_sock;
}

int	recvfile_net(const char *path, SOCKET socket)
{
	char *file = NULL;
	char *filename = NULL;
	char *buffer = NULL;
	FILE *fd_file = NULL;

	filename = recv_net(socket);

	if (path != NULL)
	{
		if ((file = calloc(strlen(path) + strlen(filename) + 1, sizeof(char))) == NULL)
			return - 1;
		strcpy(file, path);
		strcat(file, filename);
	}
	else
	{
		if ((file = calloc((strlen(filename) + 1), sizeof(char))) == NULL)
			return -1;
		strcpy(file, filename);
	}

	if ((fd_file = fopen(file, "w+")) == NULL)
	{
		perror("fopen");
		free(file);
		return -1;
	}
	buffer = malloc(sizeof(char) * 1);

	do
	{
		buffer = recv_net(socket);
		if (strcmp(buffer, "EOF") != 0)
		{
			fputs(buffer, fd_file);
			fputs("\n", fd_file);
		}
	}
	while (strcmp(buffer, "EOF") != 0);

	free(file);
	free(filename);
	free(buffer);
	fclose(fd_file);
	return 0;
}

int	send_net(SOCKET socket, const char *buffer)
{
	int bytes;

	if ((bytes = send(socket, ft_itoa(strlen(buffer) + 1), strlen(ft_itoa(strlen(buffer))) + 1, 0)) == -1)
	{
		perror("send size");
		return -1;
	}
	if ((bytes = send(socket, buffer, strlen(buffer) + 1, 0)) == -1)
	{
		perror("send buffer");
		return -1;
	}
	return 0;
}

char	*recv_net(SOCKET socket)
{
	unsigned int size;
	char *buffer = NULL;
	int bytes = 0;
	char c;
	int i = 0;

	buffer = calloc(6, sizeof(char));
	do 
	{
		bytes = recv(socket, &c, 1, MSG_WAITALL);
		if (bytes == -1)
		{
			perror("recv size");
			return NULL;
		}
		buffer[i++] = c;
	}
	while (c != 0);

	size = atoi(buffer);
	buffer = realloc(buffer, sizeof(char) * size);
	bzero(buffer, size);

	i = 0;
	do
	{
		bytes = recv(socket, &c, 1, MSG_WAITALL);
		if (bytes == -1)
		{
			perror("recv buffer");
			return NULL;
		}
		buffer[i++] = c;
	}
	while (c != 0);
	printf("buffer recv = %s\n", buffer);

	return buffer;
}
