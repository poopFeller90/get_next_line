#include "get_next_line.h"

int	ft_check_nl(t_fragment *head)
{
	int	i;

	if (!head)
		return (0);
	i = 0;
	while (head->buff[i])
	{
		if (head->buff[i++] == '\n')
			return (1);
	}
	return (0);
}

void	ft_create_lst(t_fragment **head, int fd)
{
	t_fragment	*tmp;

	if (!head)
		return ;
	if (!*head)
		ft_add_back(head, fd);
	tmp = *head;
	while (!ft_check_nl(tmp))
	{
		ft_add_back(&tmp, fd);
		tmp = tmp->next;
	}
}

char	*get_next_line(int fd)
{
	char				*ret;
	static t_fragment	*head;

	ret = NULL;
	if (!ft_check_nl(head))
		ft_create_lst(&head, fd);
	printf("%s$\n", head->buff);
	head = head->next;
	printf("test %s$\n", head->buff);
	//ret = ft_extract_nl(head);
	//ft_reset(head);
	return (ret);
}

int	main()
{
	int	fd;

	fd = open("./text.txt", O_RDWR);
	printf("%s$\n", get_next_line(fd));
	printf("%s$\n", get_next_line(fd));
	//printf("%s$\n", get_next_line(fd));
	//printf("%s$\n", get_next_line(fd));
	//printf("%s$\n", get_next_line(fd));
	return (0);
}
