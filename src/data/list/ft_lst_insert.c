/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 22:56:41 by kiroussa          #+#    #+#             */
/*   Updated: 2023/12/12 19:18:06 by kiroussa         ###   ########.fr       */
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
