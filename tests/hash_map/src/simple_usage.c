/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_usage.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:42:25 by kiroussa          #+#    #+#             */
/*   Updated: 2024/02/20 19:26:52 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"
#include <ft/data/map.h>

t_map	*g_map;

static uint64_t hash(void *intinatrenchcoat)
{
	return (uint64_t)intinatrenchcoat;
}

PRE({
	g_map = ft_map_new(10, hash, NULL); 
})

DEFINE_TEST(putget, "Can put/get an element", {
	ASSERT_NEQ(g_map, NULL);
	ft_map_put(g_map, (void *)1, (void *)2, NULL);
	uint64_t value = (uint64_t)ft_map_get(g_map, (void *)1);
	ASSERT_EQ(value, 2);
	ASSERT_EQ(ft_map_size(g_map), 1);
	ft_map_clear(g_map, NULL);
	ASSERT_EQ(ft_map_size(g_map), 0);
})

DEFINE_TEST(canremove, "Can remove elements", {
	ASSERT_NEQ(g_map, NULL);
	ft_map_put(g_map, (void *)1, (void *)2, NULL);
	ft_map_put(g_map, (void *)2, (void *)3, NULL);
	ft_map_put(g_map, (void *)3, (void *)4, NULL);
	ASSERT_EQ(ft_map_size(g_map), 3);
	ft_map_remove(g_map, (void *)2, NULL);
	ASSERT_EQ(ft_map_size(g_map), 2);
	ASSERT_EQ(ft_map_get(g_map, (void *)2), NULL);
	ASSERT(ft_map_contains(g_map, (void *)1));
	ASSERT(ft_map_contains(g_map, (void *)3));
	ft_map_clear(g_map, NULL);
	ASSERT(!ft_map_contains(g_map, (void *)1));
	ASSERT(!ft_map_contains(g_map, (void *)3));
	ASSERT_EQ(ft_map_size(g_map), 0);
})

POST({
	ft_map_free(&g_map, NULL);
})
