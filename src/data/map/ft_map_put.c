/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_put.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:55:49 by kiroussa          #+#    #+#             */
/*   Updated: 2024/02/20 18:55:58 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/data/map.h>
#include <stdlib.h>

static t_map_node	*ft_map_node_new(void *key, void *value)
{
	t_map_node	*node;

	node = (t_map_node *)malloc(sizeof(t_map_node));
	if (!node)
		return (NULL);
	node->key = key;
	node->value = value;
	return (node);
}

void	*ft_map_put(t_map *map, void *key, void *value, t_map_dealloc *dealloc)
{
	t_list		**bucket;
	t_map_node	*node;

	if (ft_map_contains(map, key))
		ft_map_remove(map, key, dealloc);
	node = ft_map_node_new(key, value);
	if (!node)
		return (NULL);
	bucket = &map->buckets[map->hash(key) % map->n_buckets];
	ft_lst_tadd(bucket, node);
	return (value);
}
