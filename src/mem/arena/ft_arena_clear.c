/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arena_clear.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 16:01:58 by kiroussa          #+#    #+#             */
/*   Updated: 2024/04/10 16:02:47 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/mem/arena.h>

void	ft_arena_clear(t_arena *arena)
{
	if (!arena || !arena->base || !arena->size)
		return ;
	arena->offset = 0;
}
