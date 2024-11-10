#include "get_next_line.h"

static void	ft_putstr(char *str)
{
	while(*str)
		write(1, str++, 1);
}

static int	ft_strlen(char *str)
{
	int	cnt;

	cnt = 0;
	while(*str++)
		cnt++;
	return (cnt);
}

char	*get_next_line(int fd)
{
	int			i;
	size_t		sz;
	static char	buffer[BUFFER_SIZE];
	char		*ret;

	buffer[BUFFER_SIZE - 1] = '\0';
	i = 0;
	//printf("fd = %d\n", fd);
	while (read(fd, buffer + i, 1) && buffer[i] != '\n')
		i++;
	buffer[i] = '\0';
	sz = ft_strlen(buffer);
	//ret = malloc((sz + 1) * sizeof(char));
	ret = strndup(buffer, sz);
	ft_putstr(buffer);
	return (ret);
}

int	main()
{
	int	i;
	int	fd;

	i = 5;
	fd = open("./test.txt", O_RDWR);
	while (i--)
		get_next_line(fd);
	close(fd);
	return (0);
}
