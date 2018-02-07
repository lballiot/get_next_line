/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lballiot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 11:32:35 by lballiot          #+#    #+#             */
/*   Updated: 2017/12/11 13:59:22 by lballiot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_copy(int i, const char *s, int start)
{
	char		*str;

	if (!(str = (char*)malloc(sizeof(char) * i)))
		return (NULL);
	ft_strncpy(str, (const char *)s + start, i);
	str[i] = '\0';
	return (str);
}

char			*ft_strtrim(char const *s)
{
	int		i;
	char	*str;
	int		end;
	int		start;

	if (!s)
		return (NULL);
	if (s[0] == '\0')
		return ((char *)s);
	str = (char *)s;
	i = ft_strlen(s) - 1;
	while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
		i--;
	end = i;
	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
		i++;
	start = i;
	i = end - start + 1;
	if (i < 0)
		i = 0;
	return (ft_copy(i, s, start));
}
