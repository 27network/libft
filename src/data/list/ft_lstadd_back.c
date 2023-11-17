/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 23:03:10 by kiroussa          #+#    #+#             */
/*   Updated: 2023/11/17 20:56:02 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/data/list.h>

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*prev;

	if (!alst || !new)
		return ;
	if (!*alst)
		*alst = new;
	else
	{
		prev = *alst;
		while (prev->next)
			prev = prev->next;
		prev->next = new;
	}
}
