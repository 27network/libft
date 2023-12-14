/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_contains.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 00:18:05 by kiroussa          #+#    #+#             */
/*   Updated: 2023/12/15 00:18:29 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/data/map.h>

bool	ft_map_contains(t_map *map, void *key)
{
	t_list		*item;
	t_map_item	*map_item;

	if (!map || !key)
		return (false);
	item = map->items;
	while (item)
	{
		map_item = (t_map_item *)item->content;
		if (map_item->key == key)
			return (true);
		item = item->next;
	}
	return (false);
}
