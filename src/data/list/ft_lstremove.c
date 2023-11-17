/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstremove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 21:39:49 by kiroussa          #+#    #+#             */
/*   Updated: 2023/11/17 20:55:57 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/data/list.h>

void	ft_lstremove(t_list **lst, t_list *node, void (*del)(void *))
{
	t_list	*tmp;

	if (!lst || !*lst || !node)
		return ;
	if (*lst == node)
	{
		*lst = node->next;
		ft_lstdelone(node, del);
		return ;
	}
	tmp = *lst;
	while (tmp->next && tmp->next != node)
		tmp = tmp->next;
	if (tmp->next)
	{
		tmp->next = node->next;
		ft_lstdelone(node, del);
	}
}
