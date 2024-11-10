#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdio.h>		// Remove lator
#include <fcntl.h>		// Remove lator
#include <string.h>		// Remove lator
#include <stdlib.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
#endif

char	*get_next_line(int fd);

#endif
