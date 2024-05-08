/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 16:04:26 by kiroussa          #+#    #+#             */
/*   Updated: 2024/05/08 14:37:58 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

DEFINE_TEST(simpleuse, "Can create and use an arena entirely", {
	t_arena *arena = ft_arena_new(1024);
	ASSERT_NEQ(arena, NULL);
	ASSERT_NEQ(arena->base, NULL);
	ASSERT_EQ(arena->size, 1024);
	ASSERT_EQ(arena->offset, 0);

	void *ptr = ft_arena_alloc(arena, 128);
	ASSERT_NEQ(ptr, NULL);
	ASSERT_EQ(arena->offset, 128);

	ft_arena_clear(arena);
	ASSERT_EQ(arena->offset, 0);

	ptr = ft_arena_alloc(arena, 1024);
	ASSERT_NEQ(ptr, NULL);
	ASSERT_EQ(arena->offset, 1024);

	ft_arena_clear(arena);
	ASSERT_EQ(arena->offset, 0);

	int *arr = ft_arena_alloc(arena, 3 * sizeof(int));
	ASSERT_NEQ(arr, NULL);
	arr[0] = 1;
	arr[1] = 2;
	arr[2] = 3;
	ASSERT_EQ(arr[0], 1);
	ASSERT_EQ(arr[1], 2);
	ASSERT_EQ(arr[2], 3);

	ft_arena_free(arena);
});
