//////////////////////////////////////////////////////////////////
// GNL OK      IDEM ../get_next_line.c without com              //
// 3failed test moulitest                                       //
//////////////////////////////////////////////////////////////////


#include "get_next_line.h"
#include <fcntl.h>
#include "libft/libft.h"
#include <stdio.h>

/*
** fct qui retourne l'index a partir duquel il y a un \n
*/

int ft_len(char *str)
{
    int i;
    int t;

    i = ft_strlen(str);
    t = 0;
    while (str[t] != '\n' && str[t] != '\0')
    {
        t++;
        i--;
    }
    return (t);
}

/*
** fct qui retourne l'index a partir du quel il n'y a plus de \n
*/

int ft_len2(char *str)
{
    int i;

    i = 0;
    while (str[i] == '\n' && str[i] != '\0')
    {
        i++;
    }
    return (i);
}

int get_next_line(const int fd, char **line)
{
    int i;
    char *buf;
    char *tmp;
    static char *str;
    int counter;

    i = 0;
    buf= ft_strnew(BUFF_SIZE);
    tmp = ft_strnew(1);
    counter = 0;
    if (fd < 0 || line == NULL || BUFF_SIZE < 1)
    {
        free(tmp);
        free(buf);
        free(str);
        return (-1);
    }
    if (str)
    {
        if (ft_len2(str) > 0)
            str = ft_strdup(ft_strsub(str, ft_len2(str), (ft_strlen(str) - ft_len2(str))));
        if (!(ft_strchr(str, '\n') == NULL)) //si il y a un \n
        {
            if (ft_len(str) > 0)
                tmp = ft_strdup(ft_strsub(str, 0, ft_len(str)));
            *line = ft_strdup(tmp);
            if (ft_strstr(str, "\n") != NULL)
                str = ft_strdup(ft_strstr(str, "\n"));
            free(tmp);
            free(buf);
            return (1);
        }
        tmp = ft_strdup(str + ft_len2(str));
        ft_strdel(&str);
    }
    while ((i = read(fd, buf, BUFF_SIZE)) != EOF && i > 0)
    {
        if (!(ft_strchr(buf, '\n') == NULL)) //si il y a un \n
        {
            if (ft_len(buf) > 0)
                tmp = ft_strjoin(tmp, ft_strsub(buf, 0, ft_len(buf)));
            *line = ft_strdup(tmp);
            if (ft_strstr(buf, "\n") != NULL)
                str = ft_strdup(ft_strstr(buf, "\n"));
            free(tmp);
            free(buf);
            return (1);
        }
        tmp = ft_strjoin(tmp, buf);
        ft_strclr(buf);
    }
    if ((i == 0 && tmp[0] == '\0') || i == -1)
    {
        free(tmp);
        free(buf);
        free(str);
        return (i);
	}
	free(tmp);
	free(buf);
	free(str);
	return (0);
}
