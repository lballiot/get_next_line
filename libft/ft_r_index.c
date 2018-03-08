/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_r_index.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lballiot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 12:20:42 by lballiot          #+#    #+#             */
/*   Updated: 2018/03/08 12:20:44 by lballiot         ###   ########.fr       */
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
