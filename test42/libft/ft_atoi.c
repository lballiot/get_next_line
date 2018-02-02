/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lballiot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 11:04:38 by lballiot          #+#    #+#             */
/*   Updated: 2017/12/11 13:51:22 by lballiot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		i;
	int		isneg;
	int		nb;

	i = 0;
	nb = 0;
	isneg = 0;
	while (((str[i] >= 8) && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-')
		isneg = 1;
	if ((str[i] == '+') || str[i] == '-')
		i++;
	while ((str[i] >= '0' && str[i] <= '9') && str[i])
	{
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	if (isneg == 1)
		return (-nb);
	else
		return (nb);
}
