/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lballiot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 11:22:05 by lballiot          #+#    #+#             */
/*   Updated: 2018/02/27 18:17:11 by karakhirn        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>
/*
** fct qui retourne l'index a partir duquel il y a un \n
*/

int		find_firstN(char *str)
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

int		find_lastN(char *str)
{
	int i;

	i = 0;
	while (str[i] == '\n' && str[i] != '\0')
		i++;
	return (i);
}

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
			if (find_firstN(buf) > 0)
			{
				cpy = ft_strsub(buf, 0, find_firstN(buf));
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
	static t_struct	*list;
	t_struct *new;
	t_struct *tmplist;

	new = ft_listnew(fd);
	if (check_list(list, fd) == 1)
	{
		ft_listadd(&list, new);
	}
	if (list)
	{
		tmplist = list;
		while (list->fd != fd)
		{
			if (list->next != NULL)
				list = list->next;
		}
	}
	tmp = ft_strnew(1);
	if (fd < 0 || line == NULL || BUFF_SIZE < 1)
		return (-1);
	if (list->str)
	{
		if ((list->str[0] == '\n' && list->str[1] == '\n' && list->str[2] == '\0'))
			return (ft_return(line, list));
		if (find_lastN(list->str) > 0)
			list->str = ft_strsub(list->str, find_lastN(list->str),
								 (ft_strlen(list->str) - find_lastN(list->str)));
		if (ft_strchr(list->str, '\n'))
		{
			if (find_firstN(list->str) > 0)
				tmp = ft_strsub(list->str, 0, find_firstN(list->str));
			*line = ft_strdup(tmp);
			if (ft_strstr(list->str, "\n"))
				list->str = ft_strdup(ft_strstr(list->str, "\n"));
			list = tmplist;
			return (1);
		}
		tmp = ft_strdup(list->str);
		ft_strdel(&list->str);
	}
	return (ft_read(list, tmp, line, fd));
}
