/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 19:38:26 by kiroussa          #+#    #+#             */
/*   Updated: 2024/03/22 18:38:58 by kiroussa         ###   ########.fr       */
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

t_mat3d	ft_mat3d_identity(void);
t_mat3d	ft_mat3d_mult(t_mat3d a, t_mat3d b);
t_mat3d	ft_mat3d_scale(double sx, double sy, double sz);
t_mat3d	ft_mat3d_rot(double theta_x, double theta_y, double theta_z);
t_mat3d	ft_mat3d_rot_vec3d(t_vec3d v);

t_vec3d	ft_vec3d_mult_mat3d(t_vec3d v, t_mat3d m);

t_mat3d	ft_mat3d_rot_x(double theta);
t_mat3d	ft_mat3d_rot_y(double theta);
t_mat3d	ft_mat3d_rot_z(double theta);

# endif // __FT_MATH_MATRIX_H__
#endif // MATRIX_H
