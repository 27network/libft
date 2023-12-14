/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_remove.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 00:07:23 by kiroussa          #+#    #+#             */
/*   Updated: 2023/12/15 00:14:55 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/data/map.h>
#include <ft/mem.h>
#include <stdlib.h>

void	ft_map_remove(t_map *map, void *key, t_map_dealloc dealloc)
{
	t_list		*item;
	t_map_item	*map_item;

	if (!map || !key)
		return ;
	if (!dealloc)
		dealloc = (t_map_dealloc)free;
	item = map->items;
	while (item)
	{
		map_item = (t_map_item *)item->content;
		if (!map->cmp(map_item->key, key))
		{
			ft_lst_remove(&map->items, item, (t_lst_dealloc)dealloc);
			return ;
		}
		item = item->next;
	}
}
