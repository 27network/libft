/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v3d_mult_m3d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 19:50:50 by kiroussa          #+#    #+#             */
/*   Updated: 2024/11/06 23:33:12 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/math/matrix.h>

__attribute__((always_inline))
t_vec3d	v3d_mult_m3d(t_vec3d v, t_mat3d m)
{
	t_vec3d		result;

	result.x = v.x * m.m[0][0] + v.y * m.m[1][0] + v.z * m.m[2][0];
	result.y = v.x * m.m[0][1] + v.y * m.m[1][1] + v.z * m.m[2][1];
	result.z = v.x * m.m[0][2] + v.y * m.m[1][2] + v.z * m.m[2][2];
	return (result);
}
