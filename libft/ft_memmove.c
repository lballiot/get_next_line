/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lballiot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 14:48:47 by lballiot          #+#    #+#             */
/*   Updated: 2017/12/11 13:54:46 by lballiot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*str;
	char	*dst;

	str = (char *)src;
	dst = (char *)dest;
	if (n == 0)
		return (dest);
	if (str > dst)
		while (n--)
			*dst++ = *str++;
	else
	{
		dst += n - 1;
		str += n - 1;
		while (n--)
			*dst-- = *str--;
	}
	return (dest);
}
