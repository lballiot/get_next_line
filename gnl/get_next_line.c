/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lballiot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 11:22:05 by lballiot          #+#    #+#             */
/*   Updated: 2018/02/19 14:24:14 by lballiot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
** fct qui retourne l'index a partir duquel il y a un \n
*/

int		ft_len(char *str)
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

int		ft_len2(char *str)
{
	int i;

	i = 0;
	while (str[i] == '\n' && str[i] != '\0')
	{
		i++;
	}
	return (i);
}
/*
t_lst	check(l_lst l, char *str, char **line)
{
	if (str)
	{
		if ((str[0] == '\n' && str[1] == '\n' && str[2] == '\0'))
		{
			*line = NULL;
			str = ft_strdup(ft_strsub(str, 1, (ft_strlen(str) - 2)));
			return (1);
		}
		if (ft_len2(str) > 0)
			str = ft_strdup(ft_strsub(str, ft_len2(str),
										(ft_strlen(str) - ft_len2(str))));
		if (ft_strchr(str, '\n'))
		{
			if (ft_len(str) > 0)
				l.tmp = ft_strdup(ft_strsub(str, 0, ft_len(str)));
			*line = ft_strdup(l.tmp);
			if (ft_strstr(str, "\n"))
				str = ft_strdup(ft_strstr(str, "\n"));
			return (1);
		}
		l.tmp = ft_strdup(str + ft_len2(str));
		ft_strdel(&str);
	}
}
*/
int		get_next_line(const int fd, char **line)
{
	l_lst l;
	static char	*str;

	l.i = 0;
	l.buf = NULL; 
	l.tmp = NULL;
//	l.buf = ft_strnew(BUFF_SIZE);
//	l.tmp = ft_strnew(1);
	if (fd < 0 || line == NULL || BUFF_SIZE < 1)
		return (-1);
	if (str)
	{
//		ft_putstr("IF STR\n");
//		ft_putstr("tmp =");
//		if (l.tmp)
//			ft_putstr(l.tmp);
//		else
//			ft_putstr("(null)");
//		ft_putstr("= tmp\n");
//		ft_putstr("str =");
//		if (str)
//			ft_putstr(str);
//		else
//			ft_putstr("(null)");
//		ft_putstr("= str\n");
		if ((str[0] == '\n' && str[1] == '\n' && str[2] == '\0'))
		{
			*line = NULL;
			str = ft_strdup(ft_strsub(str, 1, (ft_strlen(str) - 2)));
			return (1);
		}
		if (ft_len2(str) > 0)
			str = ft_strdup(ft_strsub(str, ft_len2(str),
										(ft_strlen(str) - ft_len2(str))));
//		ft_putstr("str =");
//		if (str)
//			ft_putstr(str);
//		else
//			ft_putstr("(null)");
//		ft_putstr("= str\n");
		if (ft_strchr(str, '\n'))
		{
//			ft_putstr("LALA\n");
			if (ft_len(str) > 0)
				l.tmp = ft_strdup(ft_strsub(str, 0, ft_len(str)));
			*line = ft_strdup(l.tmp);
			if (ft_strstr(str, "\n"))
				str = ft_strdup(ft_strstr(str, "\n"));
			return (1);
		}
		l.tmp = ft_strdup(str + ft_len2(str));
//		ft_putstr("tmp after dup =");
//		if (l.tmp)
//			ft_putstr(l.tmp);
//		else
//			ft_putstr("(null)");
//		ft_putstr("= tmp after dup\n");
		ft_strdel(&str);
	}
	l.buf = ft_strnew(BUFF_SIZE + 1);
	while ((l.i = read(fd, l.buf, BUFF_SIZE)) != EOF && l.i > 0)
	{
//		l.tmp = ft_strnew(BUFF_SIZE);
//		ft_putstr("buf =");
//		ft_putstr(l.buf);
//		ft_putstr("= buf\n");
		if (ft_strchr(l.buf, '\n'))
		{
			if (ft_len(l.buf) > 0)
				l.tmp = ft_strjoin(l.tmp, ft_strsub(l.buf, 0, ft_len(l.buf)));
//		ft_putstr("buf =");
//		ft_putstr(l.buf);
//		ft_putstr("= buf\n");
//		ft_putstr("tmptitit =");
//		ft_putstr(l.tmp);
//		ft_putstr("= tmptitit\n");
			*line = ft_strdup(l.tmp);
			if (ft_strstr(l.buf, "\n"))
				str = ft_strdup(ft_strstr(l.buf, "\n"));
//			ft_putstr("\nfirst return\n\n");
			return (1);
		}
//		ft_putstr("buf =");
//		ft_putstr(l.buf);
//		ft_putstr("= buf\n");
//		ft_putstr("tmptoto =");
//		ft_putstr(l.tmp);
//		ft_putstr("= tmptoto\n");
		l.tmp = ft_strjoin(l.tmp, l.buf);
		ft_strdel(&l.buf);
	}
//	ft_putstr("\nEND BOUCLE\n");
//	ft_putstr("tmp =");
//	ft_putstr(l.tmp);
//	ft_putstr("= tmp\n");
	if ((l.i == 0 && l.tmp[0] == '\0') || l.i == -1)
	{
//		ft_putstr("titi\n");
		return (l.i);
	}
	if (l.tmp)
	{
//		ft_putstr("titi\n");
		*line = ft_strdup(l.tmp);
		return (1);
	}
	return (l.i);
}


/*
	if (str)
	{
		if ((str[0] == '\n' && str[1] == '\n' && str[2] == '\0'))
		{
			*line = NULL;
			str = ft_strdup(ft_strsub(str, 1, (ft_strlen(str) - 2)));
			return (1);
		}
		if (ft_len2(str) > 0)
			str = ft_strdup(ft_strsub(str, ft_len2(str),
										(ft_strlen(str) - ft_len2(str))));
		if (ft_strchr(str, '\n'))
		{
			if (ft_len(str) > 0)
				l.tmp = ft_strdup(ft_strsub(str, 0, ft_len(str)));
			*line = ft_strdup(l.tmp);
			if (ft_strstr(str, "\n"))
				str = ft_strdup(ft_strstr(str, "\n"));
			return (1);
		}
		l.tmp = ft_strdup(str + ft_len2(str));
		ft_strdel(&str);
	}
*/
