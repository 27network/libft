/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mat3d_rot_y.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 20:02:05 by kiroussa          #+#    #+#             */
/*   Updated: 2024/03/22 18:43:20 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/math/matrix.h>
#include <math.h>

t_mat3d	ft_mat3d_rot_y(double theta)
{
	t_mat3d		result;

	result = ft_mat3d_identity();
	result.m[0][0] = cos(theta);
	result.m[0][2] = sin(theta);
	result.m[2][0] = -sin(theta);
	result.m[2][2] = cos(theta);
	return (result);
}
