/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lballiot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 10:33:22 by lballiot          #+#    #+#             */
/*   Updated: 2017/12/11 13:55:51 by lballiot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	tmp[12];
	int		i;

	i = 0;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		if (n == -2147483648)
		{
			ft_putchar_fd('2', fd);
			n = -147483648;
		}
		n = -n;
	}
	while (n > 9)
	{
		tmp[i++] = (n % 10) + 48;
		n = n / 10;
	}
	if (n < 10)
		tmp[i] = n + 48;
	while (i >= 0)
		ft_putchar_fd(tmp[i--], fd);
}
