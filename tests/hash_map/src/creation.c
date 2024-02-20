/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:10:29 by kiroussa          #+#    #+#             */
/*   Updated: 2024/02/20 19:18:54 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"
#include <ft/data/map.h>

DEFINE_TEST(create, "Can create an empty map", {
	t_map	*map;

	map = ft_map_new(10, NULL, NULL);
	ASSERT(map != NULL);
	ft_map_free(&map, NULL);
})
