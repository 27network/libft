/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m3d.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 00:43:11 by kiroussa          #+#    #+#             */
/*   Updated: 2024/11/19 16:26:56 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/math/matrix.h>

__attribute__((always_inline))
t_mat3d	m3d(t_vec3d col1, t_vec3d col2, t_vec3d col3)
{
	t_mat3d			res;

	res.m[0][0] = col1.x;
	res.m[0][1] = col2.x;
	res.m[0][2] = col3.x;
	res.m[1][0] = col1.y;
	res.m[1][1] = col2.y;
	res.m[1][2] = col3.y;
	res.m[2][0] = col1.z;
	res.m[2][1] = col2.z;
	res.m[2][2] = col3.z;
	return (res);
}
