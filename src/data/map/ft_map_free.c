/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:25:18 by kiroussa          #+#    #+#             */
/*   Updated: 2024/02/20 17:58:57 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/data/map.h>
#include <stdlib.h>

void	ft_map_free(t_map **map, t_map_dealloc *dealloc)
{
	if (!map || !*map)
		return ;
	ft_map_clear(*map, dealloc);
	free((*map)->buckets);
	free(*map);
	*map = NULL;
}
