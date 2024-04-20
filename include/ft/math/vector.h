/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 04:16:05 by kiroussa          #+#    #+#             */
/*   Updated: 2024/04/20 18:50:37 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H
# undef VECTOR_H
# ifndef __FT_MATH_VECTOR_H__
#  define __FT_MATH_VECTOR_H__

#  include <stdbool.h>

typedef struct s_vec3d
{
	double		x;
	double		y;
	double		z;
}	t_vec3d;

typedef struct s_vec2i
{
	int			x;
	int			y;
}	t_vec2i;

/* Vector3d */

t_vec3d		ft_vec3d(double x, double y, double z);
t_vec3d		ft_vec3d_clone(t_vec3d v);
bool		ft_vec3d_eq(t_vec3d v1, t_vec3d v2);

t_vec3d		ft_vec3d_add(t_vec3d v1, t_vec3d v2);
t_vec3d		ft_vec3d_sub(t_vec3d v1, t_vec3d v2);
t_vec3d		ft_vec3d_mult(t_vec3d v, double scalar);
t_vec3d		ft_vec3d_div(t_vec3d v, double scalar);

double		ft_vec3d_dot(t_vec3d v1, t_vec3d v2);
t_vec3d		ft_vec3d_cross(t_vec3d v1, t_vec3d v2);

double		ft_vec3d_len(t_vec3d v);
t_vec3d		ft_vec3d_norm(t_vec3d v);

t_vec2i		ft_vec3d_to_vec2i(t_vec3d v);

/* Vector2i */

t_vec2i		ft_vec2i(int x, int y);
t_vec2i		ft_vec2i_clone(t_vec2i v);
bool		ft_vec2i_eq(t_vec2i v1, t_vec2i v2);

# endif // __FT_MATH_VECTOR_H__
#endif // VECTOR_H
