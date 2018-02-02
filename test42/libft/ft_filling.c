/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filling.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lballiot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 17:50:57 by lballiot          #+#    #+#             */
/*   Updated: 2017/12/11 13:52:11 by lballiot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_filling(char const *s, int i, char **tab, char ch)
{
	int	size;
	int	j;
	int	i_tab;

	i_tab = 0;
	while (s[++i])
		if (s[i] == ch || i == 0)
		{
			size = 0;
			while ((s[i] == ch && s[i]))
				i++;
			j = i;
			while ((s[i] != ch && s[i++]))
				size++;
			if (!(tab[i_tab] = malloc(sizeof(char) * size + 1)))
				return (NULL);
			i = j;
			j = 0;
			while ((s[i] != ch && s[i]))
				tab[i_tab][j++] = s[i++];
			if ((s[--i] != ch && s[i] != '\0'))
				tab[i_tab++][j] = '\0';
		}
	tab[i_tab] = NULL;
	return (tab);
}
