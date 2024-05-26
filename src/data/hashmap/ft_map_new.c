/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 00:01:31 by kiroussa          #+#    #+#             */
/*   Updated: 2024/02/20 18:52:27 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/data/map.h>
#include <ft/mem.h>
#include <stdlib.h>

static int32_t	ft_map_cmp(void *a, void *b)
{
	return ((uint64_t) a - (uint64_t) b);
}

t_map	*ft_map_new(
		size_t buckets,
		t_map_hash_function *hash,
		t_map_cmp_function *cmp
) {
	t_map	*map;

	map = (t_map *)ft_calloc(1, sizeof(t_map));
	if (!map)
		return (NULL);
	map->n_buckets = buckets;
	map->buckets = (t_list **)ft_calloc(buckets, sizeof(t_list *));
	if (!map->buckets)
	{
		free(map);
		return (NULL);
	}
	map->hash = hash;
	if (!cmp)
		cmp = ft_map_cmp;
	map->cmp = cmp;
	return (map);
}
