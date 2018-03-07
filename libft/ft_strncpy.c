/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lballiot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 10:44:13 by lballiot          #+#    #+#             */
/*   Updated: 2017/12/11 13:57:58 by lballiot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, unsigned int n)
{
	int i;

	i = 0;
	if (src || dest)
	{
		while (n && src[i] != '\0')
		{
			dest[i] = src[i];
			i++;
			n--;
		}
		while (n--)
			dest[i++] = '\0';
		return (dest);
	}
	return (NULL);
}
