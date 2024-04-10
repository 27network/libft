/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 15:46:41 by kiroussa          #+#    #+#             */
/*   Updated: 2024/04/10 16:08:21 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARENA_H
# define ARENA_H
# undef ARENA_H
# ifndef __FT_MEM_ARENA_H__
#  define __FT_MEM_ARENA_H__

#  include <stddef.h>

typedef void	*(t_alloc_fn)(size_t size);

typedef struct s_arena
{
	void		*base;
	size_t		size;
	size_t		offset;
}	t_arena;

t_arena		*ft_arena_new(size_t size);
void		*ft_arena_alloc(t_arena *arena, size_t size);
void		ft_arena_clear(t_arena *arena);
void		ft_arena_free(t_arena *arena);

# endif // __FT_MEM_ARENA_H__
#endif // ARENA_H
