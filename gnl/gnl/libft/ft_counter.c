/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_counter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lballiot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 17:50:18 by lballiot          #+#    #+#             */
/*   Updated: 2017/12/11 13:52:02 by lballiot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_counter(char const *s, char ch)
{
	int	compteur;
	int	i;

	i = 0;
	if (s[i] != ch)
		compteur = 1;
	if ((s[i] == ch))
		compteur = 0;
	while (s[i])
	{
		if (s[i] == ch || i == 0)
		{
			while ((s[i] == ch && s[i]))
				i++;
			if ((s[i] != ch && s[i] != '\0'))
				compteur++;
			while ((s[i] != ch && s[i]))
				i++;
			i--;
		}
		i++;
	}
	return (compteur);
}
