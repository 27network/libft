/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v3d_min.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 00:40:24 by kiroussa          #+#    #+#             */
/*   Updated: 2024/11/18 01:21:23 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/math/vector.h>
#include <ft/math.h>

__attribute__((always_inline))
t_vec3d	v3d_min(const t_vec3d *v1, const t_vec3d *v2)
{
	return ((t_vec3d){
		.x = ft_fmin(v1->x, v2->x),
		.y = ft_fmin(v1->y, v2->y),
		.z = ft_fmin(v1->z, v2->z)});
}
