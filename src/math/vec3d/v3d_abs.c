/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v3d_abs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 00:41:37 by kiroussa          #+#    #+#             */
/*   Updated: 2024/11/18 01:21:23 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/math/vector.h>
#include <ft/math.h>

__attribute__((always_inline))
t_vec3d	v3d_abs(const t_vec3d *v)
{
	return ((t_vec3d){
		.x = ft_fabs(v->x),
		.y = ft_fabs(v->y),
		.z = ft_fabs(v->z)});
}
