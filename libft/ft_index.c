/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_index.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lballiot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 12:20:28 by lballiot          #+#    #+#             */
/*   Updated: 2018/03/08 12:20:29 by lballiot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** function that return the location of the first char send in params
*/

int		ft_index(char *str, char c)
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
