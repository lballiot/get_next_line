/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lballiot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 17:17:29 by lballiot          #+#    #+#             */
/*   Updated: 2017/12/05 17:40:40 by lballiot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strncmp(const char *s1, const char *s2, unsigned int n)
{
	if (n == 0)
		return (0);
	while (n > 1 && *s1 != '\0' && *s2 != '\0')
	{
		if (*s1 == *s2)
		{
			s1++;
			s2++;
			n--;
		}
		else
			return ((unsigned char)*s1 - (unsigned char)*s2);
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
