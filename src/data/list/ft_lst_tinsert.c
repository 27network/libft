/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_tinsert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 23:41:10 by kiroussa          #+#    #+#             */
/*   Updated: 2023/12/14 23:42:17 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/data/list.h>

t_list	*ft_lst_tinsert(t_list **list, void *content)
{
	t_list	*new_node;

	new_node = ft_lst_new(content);
	if (!new_node)
		return (NULL);
	return (ft_lst_insert(list, new_node));
}
