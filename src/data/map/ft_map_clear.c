/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_clear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:54:01 by kiroussa          #+#    #+#             */
/*   Updated: 2024/02/20 19:26:38 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/data/map.h>
#include <stdlib.h>

void	ft_map_clear(t_map *map, t_map_dealloc *dealloc)
{
	size_t		i;

	if (!map)
		return ;
	if (!dealloc)
		dealloc = (t_map_dealloc *) &free;
	i = 0;
	while (i < map->n_buckets)
	{
		ft_lst_free(&map->buckets[i], (t_lst_dealloc) dealloc);
		map->buckets[i] = NULL;
		i++;
	}
}
