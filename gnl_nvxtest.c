///////////////////////////////////////////////////////////////////////
// GNL SEGFAULT AVEC \N DANS STR                                     //
// GNL SEGFAULT AVEC SAMPLE0 MAIS LIT LE DEBUT                       //
///////////////////////////////////////////////////////////////////////


#include "get_next_line.h"
#include <fcntl.h>
#include "libft/libft.h"
#include <stdio.h>

int	ft_len(char *str)
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

int	get_next_line(const int fd, char **line)
{
	int i;
	char *buf;
	char *tmp;
	static char *str;
	int counter;
	
	counter = 0;
	i = 0;
	buf = ft_strnew(1);
	tmp = ft_strnew(1);
//	str = ft_strnew(1);
	if (str)
	{
		ft_putstr("\nIF STR\n");
		while (str[counter] == '\n')
			counter++;
		tmp = ft_strdup(str + counter);
//			tmp = ft_strdup(str);
		ft_putstr("\ntmp =");
		ft_putstr(tmp);
		ft_putstr("= tmp");
		if (!(ft_strchr(tmp, '\n') == NULL)) //si il y a un \n
		{
			*line = ft_memcpy(*line, tmp, ft_strlen(tmp));
			str = ft_strdup(ft_strstr(buf, "\n"));
			ft_putstr("\nstr =");
			ft_putstr(str);
			ft_putstr("= str");
// FREE TMP
				return (1);
			}
		}
	while ((i = read(fd, buf, BUFF_SIZE)) > 0)
	{
		ft_putstr("\nbuf avant join =");
		ft_putstr(buf);
		ft_putstr("= buf avant join");
		ft_putstr("\ntmp avant join =");
		ft_putstr(tmp);
		ft_putstr("= tmp avant join\n");
		if (!(ft_strchr(buf, '\n') == NULL)) //si il y a un \n
		{
			ft_putstr("\nTHERE IS A /N\n");
//COPIER JUSQUAU 
			ft_putstr("\ntmp =");
			ft_putstr(tmp);
			ft_putstr("= tmp\n");
			ft_putstr("\nlen : ");
			ft_putnbr(ft_len(buf));
			ft_putchar('\n');
			if (ft_len(buf) > 0)
				tmp = ft_strjoin(tmp, ft_strsub(buf, 0, ft_len(buf)));
			ft_putstr("\ntmp strsub=");
			ft_putstr(tmp);
			ft_putstr("= tmp strsub");
			*line = ft_memcpy(*line, tmp, ft_strlen(tmp));
			str = ft_strdup(ft_strstr(buf, "\n"));
			ft_putstr("\nSTR =");
			ft_putstr(str);
			ft_putstr("= STR");
			ft_putstr("\ntest");
			free(tmp);
			free(buf);
			return (1);
		}
//		else
			tmp = ft_strjoin(tmp, buf);
		ft_putstr("\nbuf =");
		ft_putstr(buf);
		ft_putstr("= buf");
		ft_putstr("\ntmp =");
		ft_putstr(tmp);
		ft_putstr("= tmp\n");
//		free(buf);
//		free(tmp);
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
