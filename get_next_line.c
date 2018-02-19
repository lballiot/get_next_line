/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lballiot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 11:22:05 by lballiot          #+#    #+#             */
/*   Updated: 2018/02/19 15:58:07 by lballiot         ###   ########.fr       */
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

static int check(char **line, char *str, char **tmp)
{
	if ((str[0] == '\n' && str[1] == '\n' && str[2] == '\0'))
	{
		*line = NULL;
		str = ft_strdup(ft_strsub(str, 1, (ft_strlen(str) - 2)));
		return (1);
	}
	if (ft_len2(str) > 0)
	{
		str = ft_strdup(ft_strsub(str, ft_len2(str),
								  (ft_strlen(str) - ft_len2(str))));
	}
	if (ft_strchr(str, '\n'))
	{
		if (ft_len(str) > 0)
			*tmp = ft_memmove(*tmp, ft_strsub(str, 0, ft_len(str)), ft_strlen(str));
		*line = ft_strdup(*tmp);
		if (ft_strstr(str, "\n"))
			str = ft_strdup(ft_strstr(str, "\n"));
		return (1);
	}
	*tmp = ft_memmove(*tmp, (str + ft_len2(str)), ft_strlen(*tmp));
	ft_strdel(&str);
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	int			i;
	char		*buf;
	char		*tmp;
	static char	*str;

	i = 0;
	buf = ft_strnew(BUFF_SIZE + 1);
//	buf = NULL;//
	tmp = ft_strnew(1);
	if (fd < 0 || line == NULL || BUFF_SIZE < 1)
		return (-1);
	if (str)
	{
		if (check(line, str, &tmp) == 1)
			return (1);
	}
//	tmp = ft_strnew(1);
/*	if (str)
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
				tmp = ft_strdup(ft_strsub(str, 0, ft_len(str)));
			*line = ft_strdup(tmp);
			if (ft_strstr(str, "\n"))
				str = ft_strdup(ft_strstr(str, "\n"));
			return (1);
		}
		tcmp = ft_strdup(str + ft_len2(str));
		ft_strdel(&str);
		}*/
//	buf = ft_strnew(BUFF_SIZE + 1);//
	while ((i = read(fd, buf, BUFF_SIZE)) != EOF && i > 0)
	{
		if (ft_strchr(buf, '\n'))
		{
			if (ft_len(buf) > 0)
				tmp = ft_strjoin(tmp, ft_strsub(buf, 0, ft_len(buf)));
			*line = ft_strdup(tmp);
			if (ft_strstr(buf, "\n"))
				str = ft_strdup(ft_strstr(buf, "\n"));
			free(tmp);
			return (1);
		}
		tmp = ft_strjoin(tmp, buf);
		ft_strclr(buf);
//		ft_strdel(&buf);
	}
//	ft_strdel(&buf);
	if ((i == 0 && tmp[0] == '\0') || i == -1)
		return (i);
	if (tmp)
	{
		*line = ft_strdup(tmp);
		return (1);
	}
	return (i);
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
				tmp = ft_strdup(ft_strsub(str, 0, ft_len(str)));
			*line = ft_strdup(tmp);
			if (ft_strstr(str, "\n"))
				str = ft_strdup(ft_strstr(str, "\n"));
			return (1);
		}
		tmp = ft_strdup(str + ft_len2(str));
		ft_strdel(&str);
	}
*/
