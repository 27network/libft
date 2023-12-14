/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_get.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 00:04:11 by kiroussa          #+#    #+#             */
/*   Updated: 2023/12/15 00:06:45 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/data/map.h>

void	*ft_map_get(t_map *map, void *key)
{
	t_list		*item;
	t_map_item	*map_item;

	if (!map || !key)
		return (NULL);
	item = map->items;
	while (item)
	{
		map_item = (t_map_item *)item->content;
		if (map_item->key == key)
			return (map_item->value);
		item = item->next;
	}
	return (NULL);
}
