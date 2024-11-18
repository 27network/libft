/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v3d_max.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 00:40:47 by kiroussa          #+#    #+#             */
/*   Updated: 2024/11/18 01:21:23 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/math/vector.h>
#include <ft/math.h>

__attribute__((always_inline))
t_vec3d	v3d_max(const t_vec3d *v1, const t_vec3d *v2)
{
	return ((t_vec3d){
		.x = ft_fmax(v1->x, v2->x),
		.y = ft_fmax(v1->y, v2->y),
		.z = ft_fmax(v1->z, v2->z)});
}
