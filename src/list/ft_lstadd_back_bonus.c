/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 23:03:10 by kiroussa          #+#    #+#             */
/*   Updated: 2023/08/07 23:06:22 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
