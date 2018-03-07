/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lballiot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 10:22:49 by lballiot          #+#    #+#             */
/*   Updated: 2017/12/11 13:58:23 by lballiot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char *str, char *to_find, int n)
{
	const char	*cpy;

	cpy = str;
	if (*to_find == '\0')
		return ((char *)cpy);
	while (*cpy && n)
	{
		if (ft_memcmp(cpy, to_find, ft_strlen(to_find)) == 0
				&& (size_t)n >= ft_strlen(to_find))
			return ((char *)cpy);
		cpy++;
		n--;
	}
	return (NULL);
}
