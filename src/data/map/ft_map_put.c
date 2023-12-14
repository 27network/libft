/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_put.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 00:02:05 by kiroussa          #+#    #+#             */
/*   Updated: 2023/12/15 00:09:30 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/data/map.h>
#include <ft/mem.h>

static t_map_item	*ft_map_item_init(void *key, void *value)
{
	t_map_item	*item;

	item = ft_calloc(1, sizeof(t_map_item));
	if (!item)
		return (NULL);
	item->key = key;
	item->value = value;
	return (item);
}

void				*ft_map_put(
		t_map *map,
		void *key,
		void *value,
		t_map_dealloc dealloc
) {
	t_map_item	*item;

	if (!map || !key || !value)
		return (NULL);
	if (ft_map_contains(map, key))
	{
		item = ft_map_get(map, key);
		if (item)
		{
			if (dealloc)
				ft_map_remove(map, key, dealloc);
			else
			{
				item->value = value;
				return (value);
			}
		}
	}
	item = ft_map_item_init(key, value);
	if (!item)
		return (NULL);
	ft_lst_tadd(&map->items, item);
	return (item);
}
