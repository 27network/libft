/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 22:55:46 by kiroussa          #+#    #+#             */
/*   Updated: 2024/05/08 14:48:11 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/data/list.h>
#include <ft/mem.h>
#include <stddef.h>

t_list	*ft_lst_new(void *content)
{
	t_list	*elem;

	elem = ft_calloc(1, sizeof(t_list));
	if (!elem)
		return (NULL);
	elem->content = content;
	elem->next = NULL;
	return (elem);
}

t_list	*ft_lstnew(void *content)
		__attribute__((weak, alias("ft_lst_new")));
