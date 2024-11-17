/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 19:38:26 by kiroussa          #+#    #+#             */
/*   Updated: 2024/11/18 00:54:11 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H
# undef MATRIX_H
# ifndef __FT_MATH_MATRIX_H__
#  define __FT_MATH_MATRIX_H__

#  include <ft/math/vector.h>

/* Matrix3d */

typedef struct s_mat3d
{
	double	m[3][3];
}	t_mat3d;

t_mat3d	m3d(t_vec3d col1, t_vec3d col2, t_vec3d col3);
t_mat3d	m3d_identity(void);
t_mat3d	m3d_inv(t_mat3d a);
double	m3d_det(t_mat3d a);
t_mat3d	m3d_mult(t_mat3d a, t_mat3d b);
t_mat3d	m3d_scale(double sx, double sy, double sz);
t_mat3d	m3d_rot(double theta_x, double theta_y, double theta_z);
t_mat3d	m3d_rot_v3d(t_vec3d v);
t_vec3d	m3d_solv(t_mat3d a, t_vec3d b);

t_vec3d	v3d_mult_m3d(t_vec3d v, t_mat3d m);
t_vec3d	m3d_mult_v3d(t_mat3d v, t_vec3d m);

t_mat3d	m3d_rot_x(double theta);
t_mat3d	m3d_rot_y(double theta);
t_mat3d	m3d_rot_z(double theta);

# endif // __FT_MATH_MATRIX_H__
#endif // MATRIX_H
