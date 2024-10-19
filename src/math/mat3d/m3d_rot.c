/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m3d_rot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 19:55:15 by kiroussa          #+#    #+#             */
/*   Updated: 2024/10/19 02:21:50 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/math/matrix.h>

t_mat3d	m3d_rot(double theta_x, double theta_y, double theta_z)
{
	t_mat3d	result;
	t_mat3d	rot_x;
	t_mat3d	rot_y;
	t_mat3d	rot_z;

	rot_x = m3d_rot_x(theta_x);
	rot_y = m3d_rot_y(theta_y);
	rot_z = m3d_rot_z(theta_z);
	result = m3d_mult(rot_x, rot_y);
	result = m3d_mult(result, rot_z);
	return (result);
}
