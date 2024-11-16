#include "get_next_line.h"

static int	ft_has_nl(char	*str)
{
	while (*str)
	{
		if (*str == '\n')
			return (1);
		str++;
	}
	return (0);
}

static char	*ft_get_line(int fd)
{
	char	*buff;

	buff = malloc(BUFFER_SIZE * sizeof(char));
	read(fd, buff, BUFFER_SIZE);
	return (buff);
}

char	*get_next_line(int fd)
{
	int			sz;
	int			offset;
	char		*ret;
	char		*bytes;
	char		*nl_pos;
	static char	*surplus;

	if (!surplus)
		bytes = ft_get_line(fd);
	while (!ft_has_nl(bytes))
	{
		bytes = ft_get_line(fd);
		sz += BUFFER_SIZE;
	}
	nl_pos = ft_strrchr(bytes, '\n');
	offset = ft_strlen(nl_pos);
	ret = malloc((sz + 1 - offset) * sizeof(char));
	return (ret);
}

int	main(void)
{
	int	fd;

	fd = open("./text.txt", O_RDWR);
	printf("%s$\n", get_next_line(fd));
	printf("%s$\n", get_next_line(fd));
	printf("%s$\n", get_next_line(fd));
	printf("%s$\n", get_next_line(fd));
	printf("%s$\n", get_next_line(fd));
	return (0);
}
