/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lballiot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 17:27:21 by lballiot          #+#    #+#             */
/*   Updated: 2017/12/11 13:53:38 by lballiot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *elem;
	t_list *tmp;
	t_list *ptr;

	elem = NULL;
	if (lst && f)
	{
		tmp = f(lst);
		elem = ft_lstnew(tmp->content, tmp->content_size);
		lst = lst->next;
		ptr = elem;
		while (lst)
		{
			tmp = f(lst);
			elem->next = ft_lstnew(tmp->content, tmp->content_size);
			lst = lst->next;
			elem = elem->next;
		}
		elem = ptr;
	}
	return (elem);
}
