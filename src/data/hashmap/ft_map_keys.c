/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 19:41:13 by kiroussa          #+#    #+#             */
/*   Updated: 2024/03/04 19:52:38 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/data/map.h>

t_list	*ft_map_keys(t_map *map)
{
	t_list	*keys;
	t_list	*map_bucket;
	size_t	index;
	size_t	size;

	index = 0;
	size = map->n_buckets;
	keys = NULL;
	while (index < size)
	{
		map_bucket = map->buckets[index];
		while (map_bucket)
		{
			ft_lst_tadd(&keys, ((t_map_node *) map_bucket->content)->key);
			map_bucket = map_bucket->next;
		}
		index++;
	}
	return (keys);
}
