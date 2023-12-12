/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 17:19:20 by kiroussa          #+#    #+#             */
/*   Updated: 2023/12/12 20:15:07 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/data/list.h>

size_t	ft_lst_size(t_list *lst)
{
	size_t	size;

	size = 0;
	if (lst)
	{
		size++;
		while (lst->next)
		{
			lst = lst->next;
			size++;
		}
	}
	return (size);
}
