/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lballiot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 11:22:05 by lballiot          #+#    #+#             */
/*   Updated: 2018/02/27 14:57:07 by karakhirn        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_check_end(char **line, t_struct *list, char *tmp)
{
	if ((list->i == 0 && tmp[0] == '\0') || list->i == -1)
		return (list->i);
	if (tmp)
	{
		*line = ft_strsub(tmp, 0, ft_strlen(tmp));
		return (1);
	}
	return (0);
}

static int	ft_read(t_struct *list, char *tmp, char **line, const int fd){

	char	*buf;
	char	*cpy;

	buf = ft_strnew(BUFF_SIZE);
	while ((list->i = read(fd, buf, BUFF_SIZE)) != EOF && list->i > 0)
	{
		if (ft_strchr(buf, '\n'))
		{
			if (ft_find_first_char(buf, '\n') > 0)
			{
				cpy = ft_strsub(buf, 0, ft_find_first_char(buf, '\n'));
				tmp = ft_strjoin_and_free(tmp, cpy);
				ft_strdel(&cpy);
			}
			*line = ft_strdup(tmp);
			ft_strdel(&tmp);
			if (ft_strstr(buf, "\n"))
				list->str = ft_strdup(ft_strstr(buf, "\n"));
			ft_strdel(&buf);
			return (1);
		}
		tmp = ft_strjoin_and_free(tmp, buf);
		ft_del_new(&buf, BUFF_SIZE);
	}
	return (ft_check_end(line, list, tmp));
}

static int	ft_return(char **line, t_struct *l, char *tmp)
{
	if (ft_find_first_char(l->str, '\n') > 0)
		tmp = ft_strsub(l->str, 0, ft_find_first_char(l->str, '\n'));
	*line = ft_strdup(tmp);
	if (ft_strstr(l->str, "\n"))
		l->str = ft_strdup(ft_strstr(l->str, "\n"));
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	char			*tmp;
	static t_struct	l;
	int				j;

	tmp = ft_strnew(1);
	if (fd < 0 || line == NULL || BUFF_SIZE < 1)
		return (-1);
	if (l.str)
	{
		if ((l.str[0] == '\n' && l.str[1] == '\n' && l.str[2] == '\0'))
		{
			*line = "";
			l.str = ft_strsub(l.str, 1, (ft_strlen(l.str) - 2));
			return (1);
		}
		if ((j = ft_find_last_char(l.str, '\n')) > 0)
			l.str = ft_strsub(l.str, j, (ft_strlen(l.str) - j));
		if (ft_strchr(l.str, '\n'))
			return (ft_return(line, &l, tmp));
		tmp = ft_strdup(l.str);
		ft_strdel(&l.str);
	}
	return (ft_read(&l, tmp, line, fd));
}
