#include "get_next_line.h"

static int ft_check_nl(t_fragment *head)
{
    int i;
    if (!head)
        return (0);
    i = 0;
    while (head->buff[i])
    {
        if (head->buff[i] == '\n')
            return (1);
        i++;
    }
    return (0);
}

static void    ft_create_lst(t_fragment **head, int fd)
{
    t_fragment  *tmp;

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

static char *ft_extract_nl(t_fragment *head)
{
    int     i;
    int     j;
    int     sz;
    char    *ret;

    j = 0;
    sz = ft_get_sz(head);
    ret = malloc((sz + 1) * sizeof(char));
    if (!ret)
        return (NULL);
    while (head)
    {
        i = 0;
        while (head->buff[i] && head->buff[i] != '\n')
            ret[j++] = head->buff[i++];
        head = head->next;
    }
    ret[j] = '\n';
    ret[sz] = '\0';
    return (ret);
}

static void ft_reset(t_fragment *head)
{
    int         i;
    int         j;
    t_fragment  *tmp;
    t_fragment  *cup;

    i = 0;
    j = 0;
    tmp = head;
    while (head->next)
        head = head->next;
    while (head->buff[i] && head->buff[i] != '\n')
        i++;
    while (head->buff[++i])
        tmp->buff[j++] = head->buff[i];
    tmp->buff[j] = '\0';
    tmp = tmp->next;
    while (tmp)
    {
        cup = tmp->next;
        free(tmp);
        tmp = cup;
    }
    head = NULL;
}

char    *get_next_line(int fd)
{
    char                *ret;
    static t_fragment   *head;

    if (!ft_check_nl(head))
        ft_create_lst(&head, fd);
    ret = ft_extract_nl(head);
    ft_reset(head);
    return (ret);
}

int main(void)
{
    int fd = open("./text.txt", O_RDWR);

    printf("%s$\n", get_next_line(fd));
    printf("%s$\n", get_next_line(fd));
    printf("%s$\n", get_next_line(fd));
    printf("%s$\n", get_next_line(fd));
    printf("%s$\n", get_next_line(fd));
    return (0);
}