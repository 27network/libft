/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:52:04 by kiroussa          #+#    #+#             */
/*   Updated: 2024/02/20 18:06:50 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/data/map.h>

size_t	ft_map_size(t_map *map)
{
	size_t		i;
	size_t		size;

	i = 0;
	size = 0;
	while (i < map->n_buckets)
	{
		size += ft_lst_size(map->buckets[i]);
		i++;
	}
	return (size);
}
