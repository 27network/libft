/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 22:56:41 by kiroussa          #+#    #+#             */
/*   Updated: 2023/11/17 20:56:03 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/data/list.h>

void	ft_lstadd_front(t_list **alst, t_list *new)
{
	t_list	*prev;

	if (!new)
		return ;
	prev = *alst;
	*alst = new;
	while (new->next)
		new = new->next;
	new->next = prev;
}
