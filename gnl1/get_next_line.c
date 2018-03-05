/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lballiot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 11:22:05 by lballiot          #+#    #+#             */
/*   Updated: 2018/03/05 12:47:54 by lballiot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>

int ft_check_end(char **line, t_struct *list, char *tmp)
{
	if ((list->i == 0 && tmp[0] == '\0') || list->i == -1)
	{
		return (list->i);
	}
	if (tmp)
	{
		ft_putstr("tmp =");
		if (tmp)
			ft_putstr(tmp);
		ft_putstr("= tmp\n");
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
//	ft_putstr("ICICI\n");
	while ((list->i = read(fd, buf, BUFF_SIZE)) != EOF && list->i > 0)
	{
		ft_putstr("buf =");
		ft_putstr(buf);
		ft_putstr("= buf\n");
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
			//ft_putstr("return\n");
			return (1);
		}
		tmp = ft_strjoin_and_free(tmp, buf);
		ft_del_new(&buf, BUFF_SIZE);
	}
	ft_putstr("list->str fin read =");
	if (list->str)
		ft_putstr(list->str);
	ft_putstr("= list->str\n");
	return (ft_check_end(line, list, tmp));
}



int ft_return(char **line, t_struct *list)
{
	*line = "";
	list->str = ft_strsub(list->str, 1, (ft_strlen(list->str) - 2));
	return (1);
}

int check_number_fd(t_struct *list, int check)
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
	list = tmp;
	return (-1);
}
// problem when list->str doesnt exist anymore for one fd 
// when its fd 3 but in list->str for the fd 4 is nothing they dont change the link's list
static t_struct *ft_struct(const int fd, t_struct **list_static, t_struct *tmp_link)
{
	t_struct *new;

	if (!(new = (t_struct *)malloc(sizeof(t_struct))))
		return (NULL);
	new->fd = fd;
	new->str = NULL;
	new->next = NULL;
	if (check_number_fd(*list_static, fd) == -1)
	{
		new->next = *list_static;
		*list_static = new;
	}
	if (*list_static)
	{
		tmp_link = *list_static;
		ft_putstr("list->fd = ");
		ft_putnbr((*list_static)->fd);
		ft_putstr("\nfd = ");
		ft_putnbr(fd);
		ft_putstr("\n");
		ft_putstr("FT_STRUCT\nlist->str =");
		if ((*list_static)->str)
			ft_putstr((*list_static)->str);
		ft_putstr("= list->str\n");
//		if ((*list_static)->fd == fd)
//		{
//			return (&*tmp_link);
//			//ft_putstr("here\n");
//		}
		while ((*list_static)->fd != fd && (*list_static)->next != NULL)
		{
//			//ft_putstr("boucle != fd\n");
			if ((*list_static)->next != NULL)
				*list_static = (*list_static)->next;
			// what are you do if list_static->next is NULL?
		}
	}
	return (&*tmp_link);
}


int		get_next_line(const int fd, char **line)
{
	char		*tmp;
	static t_struct	*list_static;
	t_struct *tmp_link = NULL;

//	list_static = NULL;
	tmp = ft_strnew(1);
	if (fd < 0 || line == NULL || BUFF_SIZE < 1)
		return (-1);
	tmp_link = ft_struct(fd, &list_static, tmp_link);
	ft_putstr("GNL\nlist->str =");
	if (list_static->str)
		ft_putstr(list_static->str);
	ft_putstr("= list->str\n");	
	ft_putstr("list->fd gnl = ");
	ft_putnbr((list_static)->fd);
	ft_putstr("\n");
	ft_putstr("list->str =");
	if (list_static->str)
		ft_putstr(list_static->str);
	ft_putstr("= list->str\n");
	if (list_static->str)
	{
		if ((list_static->str[0] == '\n' && list_static->str[1] == '\n' && list_static->str[2] == '\0'))
		{
			return (ft_return(line, list_static));
		}
		if (ft_find_last_char(list_static->str, '\n') > 0)
		{			list_static->str = ft_strsub(list_static->str, ft_find_last_char(list_static->str, '\n'),
								  (ft_strlen(list_static->str) - ft_find_last_char(list_static->str, '\n')));
			ft_putstr("toto\n");
			ft_putstr("list->str =");
			if (list_static->str)
				ft_putstr(list_static->str);
			ft_putstr("= list->str\n");
		}
		if (ft_strchr(list_static->str, '\n'))
		{
			if (ft_find_first_char(list_static->str, '\n') > 0)
				tmp = ft_strsub(list_static->str, 0, ft_find_first_char(list_static->str, '\n'));
			*line = ft_strdup(tmp);
			if (ft_strstr(list_static->str, "\n"))
				list_static->str = ft_strdup(ft_strstr(list_static->str, "\n"));
			return (1);
		}
		tmp = ft_strdup(list_static->str);
		ft_strdel(&list_static->str); // this free is the double free with multifd
	}
	return (ft_read(list_static, tmp, line, fd));
}

// don't forget to free the list_static
// problem for restart the list
