#include "get_next_line.h"

void    ft_add_back(t_fragment **node, int fd)
{
    t_fragment  *new;
    int         bread;

    if (!node)
        return ;
    new = malloc(sizeof(t_fragment));
    if (!new)
        return ;
    bread = read(fd, new->buff, BUFFER_SIZE);
    if (bread < BUFFER_SIZE)
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

int ft_get_sz(t_fragment *head)
{
    int i;
    int sz;

    sz = 0;
    while (head)
    {
        i = 0;
        while (head->buff[i] && head->buff[i] != '\n')
        {
            i++;
            sz++;
        }
        head = head->next;
    }
    return (++sz);
}