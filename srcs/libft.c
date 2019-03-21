#include "TRON_Arcade.h"

int	get_next_line(FILE *fd, char **line)
{
	int c;
	char *tmp;

	c = '0';
	tmp = malloc(sizeof(char) * 1);
	while (isprint(c))
	{
		c = fgetc(fd);
		if (c == -1)
			return -1;
		if (isprint(c))
		{
			tmp = realloc(tmp, sizeof(tmp) + 1);
			tmp[strlen(tmp)] = c;
		}
	}
	strcpy(*line, tmp);
	if (c == '\n')
		return 1;
	else
		return 0;
}

static char	*ft_strrev(char *str)
{
	int i;
	int j;
	int tmp;

	i = 0;
	j = strlen(str);
	while (j > i)
	{
		j--;
		tmp = str[i];
		str[i] = str[j];
		str[j] = tmp;
		i++;
	}
	return str;
}

char	*ft_itoa(int n)
{
	int i;
	int b;
	int reste;
	char *tmp;

	i = 0;
	b = 0;
	tmp = malloc(sizeof(char) * 13);
	bzero(tmp, 13);
	if (tmp == NULL || n == 0)
		return ((n == 0) ? "0" : NULL);
	if (n < 0)
	{
		b = 1;
		n *= -1;
	}
	while (n)
	{
		reste = n % 10;
		tmp[i++] = reste + '0';
		n /= 10;
	}
	if (b)
		tmp[i] = '-';
	tmp = ft_strrev(tmp);
	return tmp;
}
