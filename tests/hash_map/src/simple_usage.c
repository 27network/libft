/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_usage.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:42:25 by kiroussa          #+#    #+#             */
/*   Updated: 2024/03/20 21:39:04 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"
#include <ft/data/map.h>

t_map	*g_map;

static uint64_t hash(void *key)
{
	const char *str = (const char *)key;
	uint64_t hash = 5381;
	while (*str) {
		hash = (hash * 31) + *str;
		str++;
	}
	return (hash);
}

static void mapfree(t_map_node *node) {
	free(node->key);
	free(node->value);
	free(node);
}

void *_(char *s) {
	return (strdup(s));
}

PRE({
	g_map = ft_map_new(10, hash, (t_map_cmp_function *) &strcmp); 
})

// RESET({
// 	ft_map_clear(g_map, mapfree);
// })

DEFINE_TEST(putget, "Can put/get an element", {
	ASSERT_NEQ(g_map, NULL);
	ft_map_put(g_map, _("hello"), _("world"), mapfree);
	char *value = (char *)ft_map_get(g_map, "hello");
	ASSERT_STR_EQ(value, "world");
	ASSERT_EQ(ft_map_size(g_map), 1);
	ft_map_clear(g_map, mapfree);
	ASSERT_EQ(ft_map_size(g_map), 0);
})

DEFINE_TEST(keytest, "Can get map's keys", {
	ASSERT_NEQ(g_map, NULL);
	ft_map_put(g_map, _("hello"), _("world"), mapfree);
	ft_map_put(g_map, _("salut"), _("coucou"), mapfree);
	ft_map_put(g_map, _("wow"), _("incroyable"), mapfree);
	ft_map_put(g_map, _("wow"), _(":D"), mapfree);
	ASSERT_EQ(ft_map_size(g_map), 3);
	t_list *keys = ft_map_keys(g_map);
	ASSERT_NEQ(keys, NULL);
	ASSERT_EQ(ft_lst_size(keys), 3);
	ASSERT_NEQ(strstr("salutwowhello", (char *)keys->content), NULL);
	ASSERT_NEQ(strstr("salutwowhello", (char *)keys->next->content), NULL);
	ASSERT_NEQ(strstr("salutwowhello", (char *)keys->next->next->content), NULL);
	ft_lst_free(&keys, NULL);
	ft_map_clear(g_map, mapfree);
	ASSERT_EQ(ft_map_size(g_map), 0);
})

DEFINE_TEST(canremove, "Can remove elements", {
	ASSERT_NEQ(g_map, NULL);
	ft_map_put(g_map, _("hello"), _("world"), mapfree);
	ft_map_put(g_map, _("foo"), _("bar"), mapfree);
	ft_map_put(g_map, _("baz"), _("qux"), mapfree);
	ASSERT_EQ(ft_map_size(g_map), 3);
	ft_map_remove(g_map, "foo", mapfree);
	ASSERT_EQ(ft_map_size(g_map), 2);
	ASSERT_EQ(ft_map_get(g_map, "foo"), NULL);
	ASSERT(ft_map_contains(g_map, "hello"));
	ASSERT(ft_map_contains(g_map, "baz"));
	ASSERT(!ft_map_contains(g_map, "foo"));
	ft_map_clear(g_map, mapfree);
	ASSERT(!ft_map_contains(g_map, "hello"));
	ASSERT(!ft_map_contains(g_map, "baz"));
	ASSERT_EQ(ft_map_size(g_map), 0);
})

DEFINE_TEST(putoverwrite, "Can overwrite elements", {
	ASSERT_NEQ(g_map, NULL);
	ft_map_put(g_map, _("wow"), _("incroyable"), NULL);
	ft_map_put(g_map, _("wow"), _("superbe"), mapfree);
	ASSERT_EQ(ft_map_size(g_map), 1);
	char *value = (char *)ft_map_get(g_map, "wow");
	ASSERT_STR_EQ(value, "superbe");
	ft_map_clear(g_map, mapfree);
	ASSERT_EQ(ft_map_size(g_map), 0);
})

POST({
	ft_map_free(&g_map, mapfree);
})
