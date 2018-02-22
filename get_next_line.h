/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lballiot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 11:18:43 by lballiot          #+#    #+#             */
/*   Updated: 2018/02/22 12:21:53 by lballiot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 32
# include "libft/libft.h"
# include <stdio.h>

typedef	struct		s_struct
{
	char	*str;
	int		i;
}					t_struct;

int					get_next_line(const int fd, char **line);

#endif
