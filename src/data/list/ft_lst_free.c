/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 23:08:01 by kiroussa          #+#    #+#             */
/*   Updated: 2024/05/08 14:50:19 by kiroussa         ###   ########.fr       */
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

void	ft_lstclear(t_list **lst, t_lst_dealloc dealloc)
		__attribute__((weak, alias("ft_lst_free")));
