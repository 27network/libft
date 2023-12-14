/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_tget.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 23:40:26 by kiroussa          #+#    #+#             */
/*   Updated: 2023/12/14 23:40:49 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/data/list.h>

void	*ft_lst_tget(t_list *list, size_t index)
{
	t_list	*node;

	node = ft_lst_get(list, index);
	if (node)
		return (node->content);
	return (NULL);
}
