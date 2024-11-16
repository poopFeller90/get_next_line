#include "get_next_line.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*p_s;

	p_s = NULL;
	while (*s)
	{
		if (*s == (char)c)
			p_s = (char *)s;
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (p_s);
}

int	ft_strlen(char	*str)
{
	int	cnt;

	cnt = 0;
	while (*str++)
		cnt++;
	return (cnt);
}
