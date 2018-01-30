/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lballiot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 10:38:28 by lballiot          #+#    #+#             */
/*   Updated: 2017/12/11 13:57:20 by lballiot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		len;
	size_t		i;
	char		*dstcpy;
	const char	*srccpy;

	dstcpy = dst;
	srccpy = src;
	i = size;
	while (i-- != 0 && *dstcpy != '\0')
		dstcpy++;
	len = dstcpy - dst;
	i = size - len;
	if (i == 0)
		return (len + ft_strlen(srccpy));
	while (*srccpy != '\0')
	{
		if (i != 1)
		{
			*dstcpy++ = *srccpy;
			i--;
		}
		srccpy++;
	}
	*dstcpy = '\0';
	return (len + (srccpy - src));
}
