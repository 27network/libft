/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arena_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 15:57:08 by kiroussa          #+#    #+#             */
/*   Updated: 2024/04/10 16:08:55 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/mem/arena.h>
#include <ft/mem.h>

t_arena	*ft_arena_new(size_t size)
{
	t_arena	*arena;

	if (size == 0)
		return (NULL);
	arena = ft_calloc(1, sizeof(t_arena));
	if (!arena)
		return (NULL);
	arena->base = ft_calloc(1, size);
	if (!arena->base)
		free(arena);
	if (!arena->base)
		return (NULL);
	arena->size = size;
	return (arena);
}
