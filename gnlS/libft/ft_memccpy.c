/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lballiot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 10:36:28 by lballiot          #+#    #+#             */
/*   Updated: 2017/12/11 13:54:04 by lballiot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, void *src, int c, size_t n)
{
	char		*ret;
	const char	*srccpy;
	int			i;

	i = 0;
	ret = dst;
	srccpy = src;
	if (src || dst)
	{
		while (n != 0)
		{
			ret[i] = srccpy[i];
			if (srccpy[i] == (char)c)
				return (&ret[i + 1]);
			i++;
			n--;
		}
	}
	return (NULL);
}
