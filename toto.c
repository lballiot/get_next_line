//////////////////////////////////////////////////////////////////
// GNL QUI FONCTIONNE AVEC SAMPLE1 ET SAMPLE2                   //
// (oublie la derniere ligne) MAIS SEGFAULT AVEC SAMPLE0        //
// IDEM QUE GNL_OK.C AVEC COMM                                  //
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
			*line = ft_memcpy(*line, tmp, ft_strlen(tmp));
//IF IL N'Y A PAS DE \N PAS RETOURNER
			if (ft_strstr(str, "\n") != NULL)
				str = ft_strdup(ft_strstr(str, "\n"));
//			ft_putstr("\ntest");
//			free(tmp);
//			free(buf);
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
	while ((i = read(fd, buf, BUFF_SIZE)) > 0)
	{
//		ft_putstr("\nbuf avant join =");
//		ft_putstr(buf);
//		ft_putstr("= buf avant join");
//		ft_putstr("\ntmp avant join =");
//		ft_putstr(tmp);
//		ft_putstr("= tmp avant join\n");
		if (!(ft_strchr(buf, '\n') == NULL)) //si il y a un \n
		{
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
			*line = ft_memcpy(*line, tmp, ft_strlen(tmp));
			str = ft_strdup(ft_strstr(buf, "\n"));
//			ft_putstr("\ntest");
//			free(tmp);
//			free(buf);
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
//free(buf);
//free(tmp);
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
//		ft_putstr("\nFIN\n");
		ft_putendl(line);
		line = ft_strnew(900);
	}
	return (0);
}
