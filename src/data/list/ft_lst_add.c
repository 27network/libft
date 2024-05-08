/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 23:03:10 by kiroussa          #+#    #+#             */
/*   Updated: 2024/05/08 15:26:29 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/data/list.h>

t_list	*ft_lst_add(t_list **lstptr, t_list *new)
{
	t_list	*prev;

	if (!lstptr)
		return (NULL);
	if (!new)
		return (*lstptr);
	if (!*lstptr)
		*lstptr = new;
	else
	{
		prev = *lstptr;
		while (prev->next)
			prev = prev->next;
		prev->next = new;
	}
	return (*lstptr);
}

void	ft_lstadd_back(t_list **lstptr, t_list *new)
{
	(void) ft_lst_add(lstptr, new);
}
