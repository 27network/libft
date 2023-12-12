/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 23:12:40 by kiroussa          #+#    #+#             */
/*   Updated: 2023/12/12 20:15:46 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/data/list.h>
#include <stddef.h>

t_list	*ft_lst_map(t_list *lst, void *(*f)(void *), t_lst_dealloc dealloc)
{
	t_list	*new;
	t_list	*current;

	new = NULL;
	while (lst)
	{
		if (f)
			current = ft_lst_new(f(lst->content));
		if (!current && dealloc)
		{
			ft_lst_free(&current, dealloc);
			return (NULL);
		}
		ft_lst_add(&new, current);
		lst = lst->next;
	}
	return (new);
}
