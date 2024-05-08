/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_insert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 22:56:41 by kiroussa          #+#    #+#             */
/*   Updated: 2024/05/08 15:26:36 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/data/list.h>

t_list	*ft_lst_insert(t_list **lstptr, t_list *new)
{
	t_list	*prev;

	if (!lstptr)
		return (NULL);
	if (!new)
		return (*lstptr);
	prev = *lstptr;
	*lstptr = new;
	while (new->next)
		new = new->next;
	new->next = prev;
	return (new);
}

void	ft_lstadd_front(t_list **lstptr, t_list *new)
{
	(void) ft_lst_insert(lstptr, new);
}
