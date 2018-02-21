/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lballiot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 11:22:05 by lballiot          #+#    #+#             */
/*   Updated: 2018/02/19 13:22:02 by lballiot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>
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

void ft_del_new(char **str, int i)
{
	free(*str);
	
	*str = ft_strnew(i);
	
	
}
char            *ft_strjoin_and_free(char *s1, char *s2)
{
  size_t  len1;
  size_t  len2;
  char    *dest;

  len1 = 0;
  len2 = 0;
  dest = NULL;
  if (s1 && s2)
    {
      len1 = ft_strlen(s1);
      len2 = ft_strlen(s2);
      dest = ft_memalloc(len1 + len2 + 1);
      if (dest)
	{
	  dest = ft_strcat(dest, s1);
	  dest = ft_strcat(dest, s2);
	  free(s1);
	  ft_strclr(s2);
	  return (dest);
	}
    }
  free(&dest);
  return (NULL);
}


int		get_next_line(const int fd, char **line)
{
	char		*buf;
	char		*tmp;
	static t_struct	list;
	char *cpy;



//	list.i = 0;
	buf = ft_strnew(BUFF_SIZE);
	tmp = ft_strnew(1);

	if (fd < 0 || line == NULL || BUFF_SIZE < 1)
		return (-1);
	if (list.str)
	{
		if ((list.str[0] == '\n' && list.str[1] == '\n' && list.str[2] == '\0'))
		{

			*line = NULL;
			list.str = ft_strsub(list.str, 1, (ft_strlen(list.str) - 2));
			return (1);
		}
		if (ft_len2(list.str) > 0)
			list.str = ft_strsub(list.str, ft_len2(list.str), (ft_strlen(list.str) - ft_len2(list.str)));
		if (ft_strchr(list.str, '\n'))
		{
			if (ft_len(list.str) > 0)
				tmp = ft_strsub(list.str, 0, ft_len(list.str));
			*line = ft_strdup(tmp);
			if (ft_strstr(list.str, "\n"))
				list.str = ft_strdup(ft_strstr(list.str, "\n"));
			return (1);
		}
		tmp = ft_strdup(list.str);
		ft_strdel(&list.str);
	}

	while (	(list.i = read(fd, buf, BUFF_SIZE)) != EOF && list.i > 0)
	{
		if (ft_strchr(buf, '\n'))
		{
			if (ft_len(buf) > 0)
			{
				cpy = ft_strsub(buf, 0, ft_len(buf));
				tmp = ft_strjoin_and_free(tmp, cpy);
				ft_strdel(&cpy);
			}
			
			*line = ft_strdup(tmp);
			ft_strdel(&tmp);
			if (ft_strstr(buf, "\n"))
			{
				list.str = ft_strdup(ft_strstr(buf, "\n"));
			}
			
				ft_strdel(&buf);

			return (1);
		}
		cpy = ft_strdup(buf);
		tmp = ft_strjoin_and_free(tmp, cpy);
		ft_del_new(&buf, BUFF_SIZE);
		ft_strdel(&cpy);

	}
	if ((list.i == 0 && tmp[0] == '\0') || list.i == -1)
		return (list.i);

	if (tmp)
	{
		*line = ft_strdup(tmp);
		return (1);
	}
	return (list.i);
}
