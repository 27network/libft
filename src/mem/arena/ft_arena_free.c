/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arena_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 15:58:53 by kiroussa          #+#    #+#             */
/*   Updated: 2024/04/10 16:08:38 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/mem/arena.h>
#include <ft/mem.h>

void	ft_arena_free(t_arena *arena)
{
	if (arena)
	{
		if (arena->base)
			free(arena->base);
		free(arena);
	}
}
