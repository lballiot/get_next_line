////////////////////////////////////////////////////////////////////
// GNL AVEC SPLIT MAIS SANS LES COMM                              //
////////////////////////////////////////////////////////////////////

#include "get_next_line.h"
#include <fcntl.h>
#include "libft/libft.h"

int get_next_line(const int fd, char **line)
{
	int i;
	char *buf;
	static char *str;
	char **a;
	char *b;
	int j;
	char *toto;
	int t;
	j = 1;
	t = 0;

	buf = ft_strnew(BUFF_SIZE + 1);
	b = ft_strnew(1);
	if (!(a = (char **)malloc(sizeof(char *) * 5))) //modifier taille du malloc
		return (0);
	if (str)
	{
		buf = ft_strdup(str);
		a = ft_strsplit(str, '\n');
		if(a != NULL)
		{
			b = ft_strjoin(b, a[0]);
			if (a[1])
			{
				buf = ft_strdup(str);
				free(str);
				*line = ft_strdup(b);
				str = ft_strdup(ft_strstr(buf, "\n"));
				return (1);
			}
			else
				b = ft_strdup(str);
		}
	}
	else
		b = ft_strnew(1);
	while((i = read(fd, buf, BUFF_SIZE)) > 0)
	{
		a[0] = ft_strnew(BUFF_SIZE + 1);
//The idea is good but not good formulated
		if (buf[0] =='\n'|| buf[BUFF_SIZE - 1] == '\n')
		{
			*line = ft_strdup(b);
			str = ft_strdup(ft_strstr(buf, "\n"));
			free(buf);
			free(b);
			return (1);
		}
		a = ft_strsplit((const char *)buf, '\n');
		b = ft_strjoin(b, a[0]);
//Before strjoin condition if \n
		if (a[1])
		{
			free(str);
			*line = ft_strdup(b);
			ft_putendl(buf);
			free(b);
			str = ft_strdup(ft_strstr(buf, "\n"));
			return (1);
		}
		if (i == 0 && buf[0] == '\0')
			return (-1);
		buf = ft_strnew(BUFF_SIZE + 1);
		free(str);
	}
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
