/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_destroy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 00:16:57 by kiroussa          #+#    #+#             */
/*   Updated: 2023/12/15 00:17:52 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/data/map.h>
#include <stdlib.h>

void	ft_map_destroy(t_map **map, t_map_dealloc dealloc)
{
	if (!map || !*map)
		return ;
	ft_map_clear(*map, dealloc);
	free(*map);
	*map = NULL;
}
