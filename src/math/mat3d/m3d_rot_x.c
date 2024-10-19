/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m3d_rot_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 20:00:59 by kiroussa          #+#    #+#             */
/*   Updated: 2024/10/19 02:21:51 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/math/matrix.h>
#include <math.h>

t_mat3d	m3d_rot_x(double theta)
{
	t_mat3d		result;

	result = m3d_identity();
	result.m[1][1] = cos(theta);
	result.m[1][2] = -sin(theta);
	result.m[2][1] = sin(theta);
	result.m[2][2] = cos(theta);
	return (result);
}
