/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_remove.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 21:39:49 by kiroussa          #+#    #+#             */
/*   Updated: 2023/12/12 20:17:37 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/data/list.h>

t_list	*ft_lst_remove(t_list **lst, t_list *node, t_lst_dealloc dealloc)
{
	t_list	*tmp;

	if (!lst)
		return (NULL);
	if (!*lst || !node)
		return (*lst);
	if (*lst == node)
	{
		*lst = node->next;
		ft_lst_delete(node, dealloc);
		return (*lst);
	}
	tmp = *lst;
	while (tmp->next && tmp->next != node)
		tmp = tmp->next;
	if (tmp->next)
	{
		tmp->next = node->next;
		ft_lst_delete(node, dealloc);
	}
	return (*lst);
}
