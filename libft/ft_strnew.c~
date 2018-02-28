/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lballiot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 11:06:40 by lballiot          #+#    #+#             */
/*   Updated: 2017/12/11 13:58:15 by lballiot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *str;

	size = size + 1;
	if (!(str = malloc((size) * (sizeof(char)))))
		return (NULL);
	while (size != 0)
	{
		str[size - 1] = 0;
		size--;
	}
	return (str);
}
