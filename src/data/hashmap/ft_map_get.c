/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_get.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:55:27 by kiroussa          #+#    #+#             */
/*   Updated: 2024/02/20 18:02:04 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/data/map.h>

void	*ft_map_get(t_map *map, void *key)
{
	t_list		*node;
	t_map_node	*map_node;
	size_t		index;

	index = map->hash(key) % map->n_buckets;
	node = map->buckets[index];
	while (node)
	{
		map_node = (t_map_node *)node->content;
		if (map->cmp(map_node->key, key) == 0)
			return (map_node->value);
		node = node->next;
	}
	return (NULL);
}
