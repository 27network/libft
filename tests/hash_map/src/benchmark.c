/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 19:04:44 by kiroussa          #+#    #+#             */
/*   Updated: 2024/02/20 19:25:04 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/data/map.h>
#include "test.h"

#define N_TOTAL 10000
#define N_TOTAL_STR "10 000"

#define N_SEARCH 10000
#define N_SEARCH_STR "10 000"

t_map	*map;
char	keys[N_TOTAL][10];
char	random_keys[N_SEARCH][10];

static uint64_t	hash(void *k)
{
	char *key = (char *)k;
	if (strlen(key) == 1)
		return (key[0]);
	return (key[0] + key[1] + key[strlen(key) - 2] + key[strlen(key) - 1]);
}

void	freefct(t_map_node *node)
{
	free(node->key);
}

PRE({
	map = ft_map_new(10000, &hash, (t_map_cmp_function *) &strcmp);
	for (int i = 0; i < N_TOTAL; i++) {
		sprintf(keys[i], "%d", i);
	}
	for (int i = 0; i < N_SEARCH; i++) {
		sprintf(random_keys[i], "%d", rand() % 1000000);
	}
})

DEFINE_TEST(map_search, "Searching " N_SEARCH_STR " random numbers", {
	for (int i = 0; i < N_SEARCH; i++) {
		ft_map_get(map, random_keys[i]);
	}
})

DEFINE_TEST(map_insert, "Insertion of " N_TOTAL_STR " elements", {
	for (int i = 0; i < N_TOTAL; i++) {
		ft_map_put(map, keys[i], keys[i], freefct);
	}
})

POST({
	ft_map_free(&map, NULL);
})
