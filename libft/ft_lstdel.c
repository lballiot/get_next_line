/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lballiot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 17:30:19 by lballiot          #+#    #+#             */
/*   Updated: 2017/12/11 13:53:11 by lballiot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *tmp;
	t_list *tmp2;

	tmp = *alst;
	tmp2 = *alst;
	if (alst && del)
	{
		while (tmp2)
		{
			tmp = tmp->next;
			del(tmp2->content, tmp2->content_size);
			free(tmp2);
			tmp2 = tmp;
		}
		*alst = NULL;
	}
}
