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

int	sendfile_net(const char *path, const char *filename, SOCKET socket)
{
	char *file = NULL;
	char *buffer = NULL;
	FILE *fd_file = NULL;

	if (path != NULL)
	{
		file = malloc(sizeof(path) + sizeof(filename) + 1);
		bzero(file, strlen(path) + strlen(filename) + 1);
		strcpy(file, path);
		strcat(file, filename);
	}
	else
	{
		file = malloc(sizeof(filename) + 1);
		bzero(file, strlen(filename) + 1);
		strcpy(file, filename);
	}

	if ((fd_file = fopen(file, "r")) == NULL)
	{
		free(file);
		return -1;
	}

	send_net(socket, filename);

	while (get_next_line(fd_file, &buffer) > 0)
		send_net(socket, buffer);
	send_net(socket, "EOF");

	free(file);
	fclose(fd_file);
	return 0;
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
		file = malloc(sizeof(char) * (strlen(path) + strlen(filename) + 1));
		bzero(file, strlen(path) + strlen(filename) + 1);
		strcpy(file, path);
		strcat(file, filename);
	}
	else
	{
		file = malloc(sizeof(char) * (strlen(filename) + 1));
		bzero(file, strlen(filename) + 1);
		strcpy(file, filename);
	}

	if ((fd_file = fopen(file, "w+")) == NULL)
	{
		free(file);
		return -1;
	}

	while (strcmp(buffer, "EOF") != 0)
	{
		buffer = recv_net(socket);
		if (strcmp(buffer, "EOF") != 0)
			fputs(buffer, fd_file);
	}

	free(file);
	free(filename);
	free(buffer);
	fclose(fd_file);
	return 0;
}

int	send_net(SOCKET socket, const char *buffer)
{
	if (send(socket, ft_itoa(strlen(buffer) + 1), strlen(buffer) + 1, 0) == -1)
	{
		perror("send size");
		return -1;
	}
	printf("have send size\n");
	if (send(socket, buffer, strlen(buffer) + 1, 0) == -1)
	{
		perror("send buffer");
		return -1;
	}
	printf("have send buffer\n");
	return 0;
}

char	*recv_net(SOCKET socket)
{
	unsigned int size;
	char *buffer = NULL;
	int bytes = 0;

	buffer = calloc(6, sizeof(char));

	if ((bytes = recv(socket, buffer, sizeof(buffer), 0)) == -1)
	{
		perror("recv size");
		return NULL;
	}
	else
		printf("recv size: %d bytes\n", bytes);
	printf("recv size = |%s|\n", buffer);

	size = atoi(buffer);
	buffer = realloc(buffer, sizeof(char) * size);
	bzero(buffer, size);

	if ((bytes = recv(socket, buffer, sizeof(buffer), 0)) == -1)
	{
		perror("recv buffer");
		return NULL;
	}
	else
		printf("recv buffer: %d bytes\n", bytes);
	printf("recv buffer = |%s|\n", buffer);
	return buffer;
}
