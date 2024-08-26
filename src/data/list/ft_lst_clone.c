/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_clone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 14:04:59 by kiroussa          #+#    #+#             */
/*   Updated: 2024/08/26 14:05:07 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/data/list.h>

t_list	*ft_lst_clone(t_list *list, t_lst_dealloc failsafe)
{
	t_list	*new;

	if (!list)
		return (NULL);
	new = ft_lst_new(list->content);
	if (!new)
		return (NULL);
	new->next = ft_lst_clone(list->next, failsafe);
	if (!new->next)
	{
		ft_lst_free(&new, failsafe);
		return (NULL);
	}
	return (new);
}
