/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_get.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 23:39:35 by kiroussa          #+#    #+#             */
/*   Updated: 2023/12/14 23:40:14 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/data/list.h>

t_list	*ft_lst_get(t_list *list, size_t index)
{
	size_t	i;

	i = 0;
	while (list)
	{
		if (i == index)
			return (list);
		list = list->next;
		i++;
	}
	return (NULL);
}
