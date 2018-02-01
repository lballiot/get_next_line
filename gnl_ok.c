//////////////////////////////////////////////////////////////////////
// GNL PASSE LES TEST AVEC \N DANS STR MAIS PAS LES AUTRES SEGFAULT //
// TOTO.C IS THE SAME AS HERE WITH COM                              //
// PROBLEME AVEC SAMPLE0 SEGFAULT                                   //
//////////////////////////////////////////////////////////////////////

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
	buf = ft_strnew(1);
	tmp = ft_strnew(1);
	counter = 0;
	if (str)
	{
		if (ft_len2(str) > 0)
			str = ft_strdup(ft_strsub(str, ft_len2(str), (ft_strlen(str) - ft_len2(str))));
		if (!(ft_strchr(str, '\n') == NULL)) //si il y a un \n
		{
			if (ft_len(str) > 0)
				tmp = ft_strdup(ft_strsub(str, 0, ft_len(str)));
			*line = ft_memcpy(*line, tmp, ft_strlen(tmp));
			if (ft_strstr(str, "\n") != NULL)
				str = ft_strdup(ft_strstr(str, "\n"));
			return (1);
		}
		tmp = ft_strdup(str + ft_len2(str));
		ft_strdel(&str);
	}
	while ((i = read(fd, buf, BUFF_SIZE)) > 0)
	{
		if (!(ft_strchr(buf, '\n') == NULL)) //si il y a un \n
		{
			if (ft_len(buf) > 0)
				tmp = ft_strjoin(tmp, ft_strsub(buf, 0, ft_len(buf)));
			*line = ft_memcpy(*line, tmp, ft_strlen(tmp));
			str = ft_strdup(ft_strstr(buf, "\n"));
			return (1);
		}
		tmp = ft_strjoin(tmp, buf);
	}
	if (i == 0 && buf[0] == '\0')
		return (-1);
	return (0);
}

int main(int ac, char **av)
{
	int i;
	char *line;
	int fd;

	fd = open(av[1], O_RDONLY);
	line = ft_strnew(120);
	while (get_next_line(fd, &line) == 1)
	{
		ft_putendl(line);
		line = ft_strnew(900);
	}
	return (0);
}
