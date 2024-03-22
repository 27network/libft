/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mat3d_rot_x.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 20:00:59 by kiroussa          #+#    #+#             */
/*   Updated: 2024/03/22 18:43:03 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/math/matrix.h>
#include <math.h>

t_mat3d	ft_mat3d_rot_x(double theta)
{
	t_mat3d		result;

	result = ft_mat3d_identity();
	result.m[1][1] = cos(theta);
	result.m[1][2] = -sin(theta);
	result.m[2][1] = sin(theta);
	result.m[2][2] = cos(theta);
	return (result);
}
