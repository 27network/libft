/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m3d.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 00:43:11 by kiroussa          #+#    #+#             */
/*   Updated: 2024/11/18 00:43:24 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/math/matrix.h>

__attribute__((always_inline))
t_mat3d	m3d(t_vec3d col1, t_vec3d col2, t_vec3d col3)
{
	return ((t_mat3d){
		.m[0][0] = col1.x,
		.m[0][1] = col1.y,
		.m[0][2] = col1.z,
		.m[1][0] = col2.x,
		.m[1][1] = col2.y,
		.m[1][2] = col2.z,
		.m[2][0] = col3.x,
		.m[2][1] = col3.y,
		.m[2][2] = col3.z});
}