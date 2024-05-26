/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_remove.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 18:07:02 by kiroussa          #+#    #+#             */
/*   Updated: 2024/02/20 19:27:43 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/data/map.h>
#include <stdlib.h>

void	ft_map_remove(t_map *map, void *key, t_map_dealloc *dealloc)
{
	t_list	*node;
	size_t	index;
	t_list	*to_remove;

	index = map->hash(key) % map->n_buckets;
	node = map->buckets[index];
	if (!dealloc)
		dealloc = (t_map_dealloc *) &free;
	while (node)
	{
		if (map->cmp(((t_map_node *)node->content)->key, key) == 0)
		{
			to_remove = node;
			node = node->next;
			ft_lst_remove(&map->buckets[index], to_remove,
				(t_lst_dealloc) dealloc);
			return ;
		}
		node = node->next;
	}
}
