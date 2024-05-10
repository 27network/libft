/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_delete.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 23:07:22 by kiroussa          #+#    #+#             */
/*   Updated: 2024/05/10 13:49:49 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/data/list.h>
#include <stdlib.h>

void	ft_lst_delete(t_list *lst, t_lst_dealloc dealloc)
{
	if (!lst)
		return ;
	if (dealloc && lst->content)
		dealloc(lst->content);
	free(lst);
}

void	ft_lstdelone(t_list *lst, t_lst_dealloc dealloc)
		__attribute__((weak, alias("ft_lst_delete")));
