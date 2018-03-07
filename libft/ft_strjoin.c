/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lballiot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 11:13:09 by lballiot          #+#    #+#             */
/*   Updated: 2017/12/11 13:57:10 by lballiot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		size;

	if (s1 && s2)
	{
		size = ft_strlen(s1) + ft_strlen(s2);
		if (!(str = (char *)malloc(sizeof(char *) * (size + 1))))
			return (NULL);
		ft_strcpy(str, s1);
		ft_strcat(str, s2);
		return (str);
	}
	return (NULL);
}
