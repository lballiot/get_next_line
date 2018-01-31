#include "get_next_line.h"
#include <fcntl.h>
#include "libft/libft.h"

int	get_next_line(const int fd, char **line)
{
	int i;
	char *buf;
	char *tmp;
	static char *str;

	i = 0;
	buf = ft_strnew(1);
	tmp = ft_strnew(1);
	str = ft_strnew(1);
	while ((i = read(fd, buf, BUFF_SIZE)) > 0)
	{
		if (str)
			tmp = ft_strdup(str);
		if (!(ft_strchr(buf, '\n') == NULL)) //si il y a un \n
		{
			tmp = ft_memccpy(tmp, buf, '\n', BUFF_SIZE);
			*line = ft_strdup(tmp);
			str = ft_strdup(ft_strstr(buf, "\n"));
			ft_putstr("\nstr =\n");
			ft_putstr(str);
			ft_putstr("\ntest");
			return (1);
		}
		tmp = ft_strjoin(tmp, buf);
		ft_putstr("\nbuf =\n");
		ft_putstr(buf);
		ft_putstr("\ntmp =\n");
		ft_putstr(tmp);
//		free(buf);
//		free(tmp);
//		return (1);
	}
	if (i == 0 && buf[0] == '\0')
		return (-1);
	return (0);
}

int	main(int ac, char **av)
{
	int		i;
	char	*line;
	int		fd;
	
	fd = open(av[1], O_RDONLY);
	line = ft_strnew(120);
	while (get_next_line(fd, &line) == 1)
	{
		ft_putstr("\nFIN\n");
		ft_putendl(line);
		line = ft_strnew(900);
	}
	return (0);
}
