#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdio.h>		// Remove later
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
#endif

char	*get_next_line(int fd);
char	*ft_strrchr(const char *s, int c);
int	ft_strlen(char *str);

#endif
