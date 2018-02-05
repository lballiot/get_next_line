//////////////////////////////////////////////////////////////////
// GNL OK                                                       //
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
//	ft_putstr("\nlen : ");
//	ft_putnbr(t);
//	ft_putchar('\n');
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
//	ft_putstr("\nlen : ");
//	ft_putnbr(i);
//	ft_putchar('\n');
	return (i);
}

//char *ft_str(char *str, char *tmp, char **line, char *buf)
//{
//	return (tmp);
//}

int get_next_line(const int fd, char **line)
{
	int i;
//	char buf[BUFF_SIZE];
	char *buf;
	char *tmp;
	static char *str;
	int counter;

	i = 0;
	buf= ft_strnew(BUFF_SIZE);
	tmp = ft_strnew(1);
	counter = 0;
//	ft_putstr("fd : ");
//	ft_putnbr(fd);
//	ft_putchar('\n');
	if (fd < 0 || line == NULL || BUFF_SIZE < 1)
	{
		free(tmp);
		free(buf);
		free(str);
		return (-1);
	}
	if (str)
	{
//		ft_putstr("\nIF STR");
//		ft_putstr("\nstr =");
//		ft_putstr(str);
//		ft_putstr("= str");
		if (ft_len2(str) > 0)
		{
			str = ft_strdup(ft_strsub(str, ft_len2(str), (ft_strlen(str) - ft_len2(str))));
		}
//		ft_putstr("\nstr sans /n =");
//		ft_putstr(str);
//		ft_putstr("= str sans /n");
		if (!(ft_strchr(str, '\n') == NULL)) //si il y a un \n
		{
//			ft_putstr("\nTOTOTOTO\n");
//			ft_putstr("\nTHERE IS A /N\n");
//COPIER JUSQUAU
//			ft_putstr("\ntmp =");
//			ft_putstr(tmp);
//			ft_putstr("= tmp\n");
//			ft_putstr("\nbuf =");
//			ft_putstr(buf);
//			ft_putstr("= buf");
			if (ft_len(str) > 0)
			{
//				ft_putstr("toto\n");
				tmp = ft_strdup(ft_strsub(str, 0, ft_len(str)));
			}
//			ft_putstr("\ntmp strsub =");
//			ft_putstr(tmp);
//			ft_putstr("= tmp strsub");
			*line = ft_strdup(tmp);
			if (ft_strstr(str, "\n") != NULL)
				str = ft_strdup(ft_strstr(str, "\n"));
//			ft_putstr("\ntest");
			free(tmp);
			free(buf);
			return (1);
		}
//		while (str[counter] == '\n')
//			counter++;
		tmp = ft_strdup(str + ft_len2(str));
//tmp = ft_strdup(str);
//		ft_putstr("\ntmp =");
//		ft_putstr(tmp);
//		ft_putstr("= tmp");
		ft_strdel(&str);
	}
	while ((i = read(fd, buf, BUFF_SIZE)) != EOF && i > 0)
	{
//		ft_putstr("\nbuf avant join =");
//		ft_putstr(buf);
//		ft_putstr("= buf avant join");
//		ft_putstr("\ntmp avant join =");
//		ft_putstr(tmp);
//		ft_putstr("= tmp avant join\n");
		if (!(ft_strchr(buf, '\n') == NULL)) //si il y a un \n
		{
//			ft_putstr("\nTOTOTOTO\n");
//			ft_putstr("\nTHERE IS A /N IN READ\n");
//COPIER JUSQUAU
//			ft_putstr("\ntmp =");
//			ft_putstr(tmp);
//			ft_putstr("= tmp\n");
//			ft_putstr("\nlen : ");
//			ft_putnbr(ft_len(buf));
//			ft_putchar('\n');
			if (ft_len(buf) > 0)
			{
				tmp = ft_strjoin(tmp, ft_strsub(buf, 0, ft_len(buf)));
//				ft_putstr("\ntmp strsub=");
//				ft_putstr(tmp);
//				ft_putstr("= tmp strsub");
			}
//			ft_putstr("\ntmp =");
//			ft_putstr(tmp);
//			ft_putstr("= tmp\n");
//			ft_putnbr(ft_strlen(tmp));
			*line = ft_strdup(tmp);
//			ft_putstr("\nline =");
//			ft_putstr(*line);
//			ft_putstr("= line");
//			ft_putstr("\nbuf =");
//			ft_putstr(buf);
//			ft_putstr("= buf");
			if (ft_strstr(buf, "\n") != NULL)
				str = ft_strdup(ft_strstr(buf, "\n"));
//			ft_putstr("\nstr =");
//			ft_putstr(str);
//			ft_putstr("= str");
			free(tmp);
			free(buf);
			return (1);
		}
//else
		tmp = ft_strjoin(tmp, buf);
//		ft_putstr("\nbuf after join =");
//		ft_putstr(buf);
//		ft_putstr("= buf after join");
//		ft_putstr("\ntmp after join =");
//		ft_putstr(tmp);
//		ft_putstr("= tmp after join\n");
		ft_strclr(buf);
//free(tmp);
	}
//	ft_putstr("\nbuf end =");
//	ft_putstr(buf);
//	ft_putstr("= buf end");
//	ft_putstr("\ntmp tmp end =");
//	ft_putstr(tmp);
//	ft_putstr("= tmp end\n");
//	ft_putstr("\nline =");
//	ft_putstr(*line);
//	ft_putstr("= line");
	if ((i == 0 && tmp[0] == '\0') || i == -1)
	{
		free(tmp);
		free(buf);
		free(str);
		return (i);
	}
//		ft_putstr("toto\n");
	if (tmp)
	{
//		ft_putstr("\ntmp =");
//		ft_putstr(tmp);
//		ft_putstr("= tmp\n");
		*line = ft_strdup(tmp);
//		ft_putstr("\nline if =");
//		ft_putstr(*line);
//		ft_putstr("= line if");
		free(tmp);
		free(buf);
		return (1);
	}
	free(tmp);
	free(buf);
	free(str);
	return (0);
}

/*
** MY MAIN
*/
/*
#include <assert.h>
int main(int ac, char **av)
{
	char *line;
	int out;
	int p[2];
	int fd;
	int gnl_ret;

	out = dup(1);
	pipe(p);

	fd = 1;
	dup2(p[1], fd);
	write(fd, "abc\n\n", 5);
	close(p[1]);
	dup2(out, fd);
*/
	/* Read abc and new line */
//	gnl_ret = get_next_line(p[0], &line);
//	assert(gnl_ret == 1);
//	assert(strcmp(line, "abc") == 0);

	/* Read new line */
//	gnl_ret = get_next_line(p[0], &line);
//	assert(gnl_ret == 1);
//	assert(line == NULL || *line == '\0');

	/* Read again, but meet EOF */
//	gnl_ret = get_next_line(p[0], &line);
//	assert(gnl_ret == 0);
//	assert(line == NULL || *line == '\0');

	/* Let's do it once again */
//	gnl_ret = get_next_line(p[0], &line);
//	assert(gnl_ret == 0);
//	assert(line == NULL || *line == '\0');
//	return (0);
//}

/*	int i;
	char *line;
	int fd;

	(void) ac;
	fd = open(av[1], O_RDONLY);
	line = ft_strnew(120);
	while (get_next_line(fd, &line) == 1)
	{
//		ft_putstr("\nFIN\n");
		ft_putendl(line);
		line = ft_strnew(900);
	}
	ft_putnbr(get_next_line(fd, &line));
	return (0);
*/

//////////////////
// PRBLM return //
//////////////////
/*
	char *line;
	int out;
	int p[2];
	int fd;
	int ret;

	out = dup(1);
	pipe(p);

	fd = 1;
	dup2(p[1], fd);
	write(fd, "abcdefghijklmnop\n", 17);
	write(fd, "qrstuvwxyzabcdef\n", 17);
	close(p[1]);
	dup2(out, fd);
	get_next_line(p[0], &line);
	assert(strcmp(line, "abcdefghijklmnop") == 0);
	get_next_line(p[0], &line);
	assert(strcmp(line, "qrstuvwxyzabcdef") == 0);
	ret = get_next_line(p[0], &line);
	ft_putstr("\nline =");
	ft_putstr(line);
	ft_putstr("= line ");
	ft_putstr("ret :");
	ft_putnbr(ret);
	ft_putstr("\n");
	assert(ret == 0);
	return (0);
*/
