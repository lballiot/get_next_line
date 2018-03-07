/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_last_char.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lballiot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 11:31:35 by lballiot          #+#    #+#             */
/*   Updated: 2018/03/01 11:41:50 by karakhirn        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** function that return the location of the last char find send in params
*/

int		ft_r_index(char *str, char c)
{
	int i;

	i = 0;
	if (str[i] == c && str[i] != '\0')
		i++;
	return (i);
}
