/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v3d_cross.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 18:51:15 by kiroussa          #+#    #+#             */
/*   Updated: 2024/11/06 23:33:11 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/math/vector.h>

__attribute__((always_inline))
t_vec3d	v3d_cross(t_vec3d *a, t_vec3d *b)
{
	t_vec3d	c;

	c.x = a->y * b->z - a->z * b->y;
	c.y = a->z * b->x - a->x * b->z;
	c.z = a->x * b->y - a->y * b->x;
	return (c);
}