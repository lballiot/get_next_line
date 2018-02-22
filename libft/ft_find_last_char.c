/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_last_char.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lballiot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 11:31:35 by lballiot          #+#    #+#             */
/*   Updated: 2018/02/22 11:59:34 by lballiot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** function that return the location of the last char find send in params
*/

int		ft_find_last_char(char *str, char c)
{
	int i;

	i = 0;
	while (str[i] == c && str[i] != '\0')
		i++;
	return (i);
}
