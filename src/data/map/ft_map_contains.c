/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_contains.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:52:53 by kiroussa          #+#    #+#             */
/*   Updated: 2024/02/20 17:58:42 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/data/map.h>

bool	ft_map_contains(t_map *map, void *key)
{
	t_list	*node;
	size_t	index;

	index = map->hash(key) % map->n_buckets;
	node = map->buckets[index];
	while (node)
	{
		if (map->cmp(((t_map_node *) node->content)->key, key) == 0)
			return (true);
		node = node->next;
	}
	return (false);
}
