/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_clear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 00:16:13 by kiroussa          #+#    #+#             */
/*   Updated: 2023/12/15 00:16:43 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/data/map.h>
#include <ft/mem.h>
#include <stdlib.h>

void	ft_map_clear(t_map *map, t_map_dealloc dealloc)
{
	if (!map)
		return ;
	if (!dealloc)
		dealloc = (t_map_dealloc)free;
	ft_lst_free(&map->items, (t_lst_dealloc)dealloc);
}
