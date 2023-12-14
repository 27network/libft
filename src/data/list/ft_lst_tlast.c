/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_tlast.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 23:42:27 by kiroussa          #+#    #+#             */
/*   Updated: 2023/12/14 23:42:47 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/data/list.h>

void	*ft_lst_tlast(t_list *list)
{
	t_list	*node;

	node = ft_lst_last(list);
	if (node)
		return (node->content);
	return (NULL);
}
