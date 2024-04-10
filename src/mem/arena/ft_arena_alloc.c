/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arena_alloc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 16:02:55 by kiroussa          #+#    #+#             */
/*   Updated: 2024/04/10 16:03:43 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/mem/arena.h>
#include <ft/mem.h>

void	*ft_arena_alloc(t_arena *arena, size_t size)
{
	void	*ptr;

	if (!arena || !arena->base || !arena->size || size == 0)
		return (NULL);
	if (arena->offset + size > arena->size)
		return (NULL);
	ptr = arena->base + arena->offset;
	ft_bzero(ptr, size);
	arena->offset += size;
	return (ptr);
}
