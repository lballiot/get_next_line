/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_first_char.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lballiot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 11:42:35 by lballiot          #+#    #+#             */
/*   Updated: 2018/02/22 12:00:50 by lballiot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** function that return the location of the first char send in params
*/

int		ft_find_first_char(char *str, char c)
{
	int i;
	int t;

	i = ft_strlen(str);
	t = 0;
	while (str[t] != c && str[t] != '\0')
	{
		t++;
		i--;
	}
	return (t);
}
