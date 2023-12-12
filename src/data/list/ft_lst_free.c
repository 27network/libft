/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 23:08:01 by kiroussa          #+#    #+#             */
/*   Updated: 2023/12/12 19:10:04 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/data/list.h>
#include <stdlib.h>

void	ft_lst_free(t_list **lst, t_lst_dealloc dealloc)
{
	t_list	*current;
	t_list	*next;

	if (!lst)
		return ;
	current = *lst;
	while (current)
	{
		next = current->next;
		ft_lst_delete(current, dealloc);
		current = next;
	}
	*lst = NULL;
}
