/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lballiot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 11:07:06 by lballiot          #+#    #+#             */
/*   Updated: 2017/12/11 13:58:32 by lballiot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*cpy;

	i = -1;
	cpy = NULL;
	while (s[++i] != '\0')
		if (s[i] == c)
			cpy = (char *)&s[i];
	if (s[i] == c)
		cpy = (char *)&s[i];
	return (cpy);
}
