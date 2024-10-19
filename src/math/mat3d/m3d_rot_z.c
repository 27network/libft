/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m3d_rot_z.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 20:02:29 by kiroussa          #+#    #+#             */
/*   Updated: 2024/10/19 02:21:51 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/math/matrix.h>
#include <math.h>

t_mat3d	m3d_rot_z(double theta)
{
	t_mat3d		result;

	result = m3d_identity();
	result.m[0][0] = cos(theta);
	result.m[0][1] = -sin(theta);
	result.m[1][0] = sin(theta);
	result.m[1][1] = cos(theta);
	return (result);
}
