/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lballiot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 11:18:43 by lballiot          #+#    #+#             */
/*   Updated: 2018/02/27 17:25:02 by karakhirn        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 32
# include "libft/libft.h"
# include <stdio.h>

typedef	struct		s_struct
{
	char			*str;
	int				i;
	int				fd;
	struct s_struct	*next;
}					t_struct;

int					get_next_line(const int fd, char **line);

#endif
