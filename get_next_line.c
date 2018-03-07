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


int ft_read(t_struct **list, char *tmp, char **line, t_struct *tmp_link)
{
	char *buf;
	char *cpy;

	buf = ft_strnew(BUFF_SIZE);
	while (((*list)->i = read((*list)->fd, buf, BUFF_SIZE)) != EOF && (*list)->i > 0)
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
				(*list)->str = ft_strdup(ft_strstr(buf, "\n"));
			ft_strdel(&buf);
			if (tmp_link)
				(*list) = tmp_link;
			return (1);
		}
		tmp = ft_strjoin_and_free(tmp, buf);
	}
	return (ft_check_end(line, (*list), tmp, tmp_link));
}

int ft_return(char **line, t_struct **list, t_struct *tmp_link)
{
	*line = "";
	(*list)->str = ft_strsub((*list)->str, 1, (ft_strlen((*list)->str) - 2));
	(*list) = tmp_link;
	return (1);
}

int check_number_fd(t_struct **list, int check)
{
	t_struct *tmp;

	tmp = *list;
	while (*list)
	{
		if ((*list)->fd == check)
		{
			*list = tmp;
			return(0);
		}
		*list = (*list)->next;
	}
	*list = tmp;
	return (-1);
}

// problem when list->str doesnt exist anymore for one fd
// when its fd 3 but in list->str for the fd 4 is nothing they dont change the link's list

static t_struct *ft_struct(const int fd, t_struct **list_static, t_struct *tmp_link)
{
	t_struct *new;
	t_struct *end;

	end = *list_static;
	if (!(new = (t_struct *)malloc(sizeof(t_struct))))
		return (NULL);
	new->fd = fd;
	new->str = NULL;
	new->next = NULL;
	if (end)
		while (end->next != NULL)
			if (end->next != NULL)
				end = end->next;
	if (check_number_fd(list_static, fd) == -1)
	{
		if (end)
		{
			*list_static = end;
			(*list_static)->next = new;
			*list_static = tmp_link;
		}
		else
			*list_static = new;
	}
	if (*list_static)
		while ((*list_static)->fd != fd && (*list_static)->next != NULL)
			if ((*list_static)->next != NULL)
				list_static = &(*list_static)->next;
// what are you do if list_static->next is NULL?
	return (*list_static);
}


int get_next_line(const int fd, char **line)
{
	char*tmp;
	static t_struct*list_static;
	t_struct *tmp_link = NULL;

	tmp = ft_strnew(1);
	if (fd < 0 || line == NULL || BUFF_SIZE < 1)
		return (-1);

	if (!list_static)
		list_static = NULL;
	tmp_link = list_static;
	list_static = ft_struct(fd, &list_static, tmp_link);
	if (list_static->str)
	{
		if ((list_static->str[0] == '\n' && list_static->str[1] == '\n' && list_static->str[2] == '\0'))
			return (ft_return(line, &list_static, tmp_link));
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
	return (ft_read(&list_static, tmp, line, tmp_link));
}

// don't forget to free the list_static
// problem for restart the list
