#include "get_next_line.h"
#include <fcntl.h>
#include <stdlib.h>

int		get_next_line(const int fd, char **line)
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
	
//		printf("str avant=%s\n", str);
	buf = ft_strnew(BUFF_SIZE + 1);
	b = ft_strnew(1);
	if (str)
	{
//		ft_putstr("IIIIIIIFFFFFFF\n");
//		ft_putstr("\n\nSTR=");
//		ft_putstr(str);
//		ft_putstr("=STR\n\n");
//		buf = ft_strdup(str);
		if (str[BUFF_SIZE + 1] == '\n')
		{
			ft_putstr("\ntest\n");
		}
		a = ft_strsplit(str, '\n');
		if(a != NULL)
		{
			str = ft_strsub(str, 1, ft_strlen(str));

			
			b = ft_strjoin(b, a[0]);
//		ft_putstr("TOTTOTOTOTOOTOT");
//		ft_putendl(a[0]);
//		ft_putstr("\n\nSTR=");
//		ft_putstr(str);
//		ft_putstr("=STR\n\n");
//		ft_putstr("TOTTOTOTOTOOTOT");
			
			if (a[1])
			{
				buf = ft_strdup(str);
				free(str);
				*line = ft_strdup(b);
				str = ft_strdup(ft_strstr(buf, "\n"));
//		ft_putstr("\nICIIIIIIIIIIIII\n");	
				return (1);
			}
			else
				b = ft_strdup(str);
			free(str);
		}
	}
	else
		b = ft_strnew(1);
	while((i = read(fd, buf, BUFF_SIZE)) > 0)
	{
//		ft_putstr("LLLL\n");
//		a = ft_strnew(BUFF_SIZE + 1);
		a = ft_strsplit((const char *)buf, '\n');
//		ft_putstr("ICIIIIIIIIIIIII\n");
//		ft_putstr(a[0]);
		
		b = ft_strjoin(b, a[0]);
//		ft_putstr("\n\na[0]=");
//		ft_putstr(a[0]);
//		ft_putstr("=a[0]\n\n");
//		ft_putstr("\n\nB=");
//		ft_putstr(b);
//		ft_putstr("=B\n\n");
		if (a[1])
		{
//		ft_putstr("IF A[1]\n");
//		ft_putstr("\n\nB=");
//		ft_putstr(b);
//		ft_putstr("=B\n\n");
//		ft_putstr("\n\na[1]=");
//		ft_putstr(a[1]);
//		ft_putstr("=a[1]\n\n");
			free(str);
			*line = ft_strdup(b);
//		ft_putendl(buf);
//		free(b);
			str = ft_strdup(ft_strstr(buf, "\n"));
//		ft_putstr("\nICIIIIIIIIIIIII\n");	
//		ft_putstr("\nRESULT STRSTR=");
//		ft_putstr(str);
//		ft_putstr("=RESULT STRSTR\n");
//			ft_putstr("\n\ntiti\n");
			return (1);
		}
		
		
		
		buf = ft_strnew(BUFF_SIZE + 1);
//		free(str);
	}
	return (0);
}

int		main(int ac, char **av)
{
	int		i;
	char *line;
	int fd;

	fd = open(av[1], O_RDONLY);
//	line = ft_strnew(120);
	while (get_next_line(fd, &line) == 1)
	{
//		ft_putstr(line);
//		ft_putstr("\nFIN\n");
				ft_putendl(line);
//		line = ft_strnew(120);
	}
	return (0);
}
