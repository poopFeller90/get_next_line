#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdio.h>		// Remove later
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
#endif

typedef struct s_fragment
{
	char				buff[BUFFER_SIZE];
	int					sz;
	int					eof;
	struct s_fragment	*next;
}						t_fragment;

char	*get_next_line(int fd);
void	ft_add_back(t_fragment **node, int fd);

#endif
