#include "get_next_line.h"

void	ft_add_back(t_fragment **node, int fd)
{
	t_fragment	*new;
	int			bytes;

	if (!node)
		return ;
	new = malloc(sizeof(t_fragment));
	if (!new)
		return ;
	bytes = read(fd, new->buff, BUFFER_SIZE);
	if (bytes < BUFFER_SIZE)
		(*node)->eof = 1;
	if (!*node)
		*node = new;
	else if (!(*node)->next)
		(*node)->next = new;
	else
	{
		while ((*node)->next)
			*node = (*node)->next;
		(*node)->next = new;
	}
}
