/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lballiot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 14:53:38 by lballiot          #+#    #+#             */
/*   Updated: 2018/02/19 16:52:16 by lballiot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////
//                                 GNL NEW                                    //
////////////////////////////////////////////////////////////////////////////////


#include "get_next_line.h"

int check(char *str, char **line)
{
	int counter;
	char *cpy;

	cpy = ft_memalloc(1);
	counter = 0;
	if (! str)
		return (-1);
	while(str[counter] != '\0')
	{
		if (str[counter] == '\n')
		{
			*line = ft_strsub(str, 0, counter);
			counter++;
			ft_putstr("line =");
			ft_putstr(*line);
			ft_putstr("= line\n");
			cpy = ft_strdup(str);
			ft_strdel(&str);
			str = ft_strsub(cpy, counter, ft_strlen(cpy));
			ft_putstr("str after line=");
			ft_putstr(str);
			ft_putstr("= str after line\n");
			free(cpy);
			return (1);
		}
		counter++;
	}
//	tmp = ft_strdup(str)
	return (0);
}

int get_next_line(const int fd, char **line)
{
	int i;
	char *buf;
	static char *str;
	
	i = 0;
	buf = ft_strnew(BUFF_SIZE);
	str = ft_memalloc(1);
	if ((check(str, line) == 1))
	{
//		ft_putstr("THERE IS A /N\n");
//		ft_putstr("\n\n");
		return (1);
	}
    while ((i = read(fd, buf, BUFF_SIZE)) > 0)
    {
		ft_putstr("buf avant join =");
		ft_putstr(buf);
		ft_putstr("= buf avnt join\n");
		ft_putstr("str avant join =");
		ft_putstr(str);
		ft_putstr("= str avant join\n\n");	
		str = ft_strjoin(str, buf);
		ft_strclr(buf);
		ft_putstr("buf apres join =");
		ft_putstr(buf);
		ft_putstr("= buf apres join\n");
		ft_putstr("str apres join =");
		ft_putstr(str);
		ft_putstr("= str apres join\n\n");	
		if ((check(str, line) == 1))
		{
			ft_strdel(&buf);
//			ft_putstr("THERE IS A /N\n");
//			ft_putstr("\n\n");
			return (1);
		}
		ft_putstr("str apres return =");
		ft_putstr(str);
		ft_putstr("= str apres return\n\n");	
		ft_strclr(buf);
    }
	return (i);
}


/*
		ft_putstr("buf =");
		ft_putstr(buf);
		ft_putstr("= buf\n");
		ft_putstr("tmp =");
		ft_putstr(tmp);
		ft_putstr("= tmp\n");
*/
