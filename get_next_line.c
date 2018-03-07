/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lballiot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 11:11:45 by lballiot          #+#    #+#             */
/*   Updated: 2018/03/07 11:17:13 by lballiot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>

int ft_check_end(char **line, t_struct *list, char *tmp, t_struct *tmp_link)
{
	if ((list->i == 0 && tmp[0] == '\0') || list->i == -1)
		return (list->i);
	if (tmp)
	{
		*line = ft_strdup(tmp);
		list = tmp_link;
		return (1);
	}
	list = tmp_link;
	return (0);
}


int ft_read(t_struct **l, char *tmp, char **line, t_struct *tmp_link)
{
	char *buf;
	char *cpy;

	buf = ft_strnew(BUFF_SIZE);
	while (((*l)->i = read((*l)->fd, buf, BUFF_SIZE)) != EOF && (*l)->i > 0)
	{
		if (ft_strchr(buf, '\n'))
		{
			if (ft_index(buf, '\n') > 0)
			{
				cpy = ft_strsub(buf, 0, ft_index(buf, '\n'));
				tmp = ft_strjoin_and_free(tmp, cpy);
				ft_strdel(&cpy);
			}
			*line = ft_strdup(tmp);
			ft_strdel(&tmp);
			if (ft_strstr(buf, "\n"))
				(*l)->str = ft_strdup(ft_strstr(buf, "\n"));
			ft_strdel(&buf);
			if (tmp_link)
				(*l) = tmp_link;
			return (1);
		}
		tmp = ft_strjoin_and_free(tmp, buf);
	}
	return (ft_check_end(line, (*l), tmp, tmp_link));
}

int ft_return(char **line, t_struct **l, t_struct *tmp_link, int flag)
{
	char *tmp;

	tmp = ft_strnew(1);
	if (flag == 1)
	{
		*line = "";
		(*l)->str = ft_strsub((*l)->str, 1, (ft_strlen((*l)->str) - 2));
		(*l) = tmp_link;
	}
	else
	{
		if (ft_index((*l)->str, C) > 0)
			tmp = ft_strsub((*l)->str, 0, ft_index((*l)->str, C));
		*line = ft_strdup(tmp);
		if (ft_strstr((*l)->str, "\n"))
			(*l)->str = ft_strdup(ft_strstr((*l)->str, "\n"));
		*l = tmp_link;
	}
	return (1); 
}


static t_struct *ft_struct(const int fd, t_struct **list_static)
{
	t_struct *new;
	t_struct *end;

	end = *list_static;
	if (!(new = (t_struct *)malloc(sizeof(t_struct))))
		return (NULL);
	new->fd = fd;
	new->str = NULL;
	new->next = NULL;
	if (*list_static)
		while ((*list_static)->fd != fd && (*list_static)->next != NULL)
			list_static = &(*list_static)->next;
	else
		*list_static = new;
	if (((*list_static)->next == NULL && (*list_static)->fd != fd))
	{
		(*list_static)->next = new;
		list_static = &(*list_static)->next;
	}
	return (*list_static);
}


int get_next_line(const int fd, char **line)
{
	char*tmp;
	static t_struct*l;
	t_struct *tmp_link;
	
	tmp = ft_strnew(1);
	if (fd < 0 || line == NULL || BUFF_SIZE < 1)
		return (-1);
	tmp_link = l;
	l = ft_struct(fd, &l);
	if (l->str)
	{
		if ((l->str[0] == C && l->str[1] == C && l->str[2] == '\0'))
			return (ft_return(line, &l, tmp_link, 1));
		if (ft_r_index(l->str, C) > 0)
			l->str = ft_strsub(l->str, ft_r_index(l->str, C),
								 (ft_strlen(l->str) - ft_r_index(l->str, C)));
		if (ft_strchr(l->str, C))
			return (ft_return(line, &l, tmp_link, 0));
		tmp = ft_strdup(l->str);
		ft_strdel(&l->str); // this free is the double free with multifd
	}
	return (ft_read(&l, tmp, line, tmp_link));
}

// don't forget to free the l
// problem for restart the list
