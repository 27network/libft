/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m3d_mult_v3d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 00:47:19 by kiroussa          #+#    #+#             */
/*   Updated: 2024/11/18 00:55:13 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/math/matrix.h>

__attribute__((always_inline))
t_vec3d	m3d_mult_v3d(t_mat3d a, t_vec3d b)
{
	return ((t_vec3d){
		.x = a.m[0][0] * b.x + a.m[0][1] * b.y + a.m[0][2] * b.z,
		.y = a.m[1][0] * b.x + a.m[1][1] * b.y + a.m[1][2] * b.z,
		.z = a.m[2][0] * b.x + a.m[2][1] * b.y + a.m[2][2] * b.z});
}
