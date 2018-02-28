/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lballiot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 11:22:05 by lballiot          #+#    #+#             */
/*   Updated: 2018/02/28 11:31:28 by karakhirn        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>

int ft_check_end(char **line, t_struct *list, char *tmp)
{
	if ((list->i == 0 && tmp[0] == '\0') || list->i == -1)
		return (list->i);
	if (tmp)
	{
		*line = ft_strdup(tmp);
		return (1);
	}
	return (0);
}


int ft_read(t_struct *list, char *tmp, char **line, const int fd)
{
	char *buf;
	char *cpy;

	buf = ft_strnew(BUFF_SIZE);
	while (	(list->i = read(fd, buf, BUFF_SIZE)) != EOF && list->i > 0)
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

int ft_return(char **line, t_struct *list)
{
	*line = NULL;
	list->str = ft_strsub(list->str, 1, (ft_strlen(list->str) - 2));
	return (1);
}
// trasnform in : void ft_listnew(t_struct new_list, int fd)
t_struct	*ft_listnew(int fd)
{
	t_struct *new;

	new = NULL;
	if (!(new = (t_struct *)malloc(sizeof(t_struct))))
		return (NULL);
	new->fd = fd;
	new->next = NULL;
	return (new);
}

void	ft_listadd(t_struct **alst, t_struct *new)
{
	new->next = *alst;
	*alst = new;
}

int check_list(t_struct *list, int check )
{
	t_struct *tmp;

	tmp = list;
	while (list)
	{
		if (list->fd == check)
		{
			list = tmp;
			return(0);
		}
		list = list->next;
	}
	return (1);
}


int		get_next_line(const int fd, char **line)
{
	char		*tmp;
	static t_struct	*list_static;
	t_struct *new;
	t_struct *tmp_link;

	new = ft_listnew(fd);
	if (check_list(list_static, fd) == 1)
		ft_listadd(&list_static, new);
	if (list_static)
	{
		tmp_link = list_static;
		while (list_static->fd != fd)
		{
			if (list_static->next != NULL)
				list_static = list_static->next;
			// what are you do if list_static->next is NULL?
		}
	}
	tmp = ft_strnew(1);
	if (fd < 0 || line == NULL || BUFF_SIZE < 1)
		return (-1);
	if (list_static->str)
	{
		if ((list_static->str[0] == '\n' && list_static->str[1] == '\n' && list_static->str[2] == '\0'))
			return (ft_return(line, list_static));
		if (ft_find_last_char(list_static->str, '\n') > 0)
			list_static->str = ft_strsub(list_static->str, ft_find_last_char(list_static->str, '\n'),
								  (ft_strlen(list_static->str) - ft_find_last_char(list_static->str, '\n')));
		if (ft_strchr(list_static->str, '\n'))
		{
			if (ft_find_first_char(list_static->str, '\n') > 0)
				tmp = ft_strsub(list_static->str, 0, ft_find_first_char(list_static->str, '\n'));
			*line = ft_strdup(tmp);
			if (ft_strstr(list_static->str, "\n"))
				list_static->str = ft_strdup(ft_strstr(list_static->str, "\n"));
			list_static = tmp_link;
			return (1);
		}
		tmp = ft_strdup(list_static->str);
		ft_strdel(&list_static->str); // this free is the double free with multifd
	}
	return (ft_read(list_static, tmp, line, fd));
}

// don't forget to free the list_static
