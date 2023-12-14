/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_tadd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 23:40:55 by kiroussa          #+#    #+#             */
/*   Updated: 2023/12/14 23:48:43 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/data/list.h>

t_list	*ft_lst_tadd(t_list **list, void *content)
{
	t_list	*new_node;

	new_node = ft_lst_new(content);
	if (!new_node)
		return (NULL);
	return (ft_lst_add(list, new_node));
}
