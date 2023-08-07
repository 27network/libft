/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 23:12:40 by kiroussa          #+#    #+#             */
/*   Updated: 2023/08/07 23:41:48 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*current;

	new = NULL;
	while (lst)
	{
		if (f)
			current = ft_lstnew(f(lst->content));
		if (!current && del)
		{
			ft_lstclear(&current, del);
			return (NULL);
		}
		ft_lstadd_back(&new, current);
		lst = lst->next;
	}
	return (new);
}
