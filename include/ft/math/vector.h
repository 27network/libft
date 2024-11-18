/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 04:16:05 by kiroussa          #+#    #+#             */
/*   Updated: 2024/11/18 01:20:39 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H
# undef VECTOR_H
# ifndef __FT_MATH_VECTOR_H__
#  define __FT_MATH_VECTOR_H__

#  include <stdbool.h>

typedef double	t_v3d	__attribute__((aligned(32),
							vector_size(sizeof(double) * 4)));

typedef union u_vec3d
{
	t_v3d		v;
	struct
	{
		double		x;
		double		y;
		double		z;
		double		w;
	}
	__attribute__((aligned(32)));
}	t_vec3d
__attribute__((aligned(32)));

typedef int		t_v2i	__attribute__((aligned(16),
							vector_size(sizeof(int) * 2)));

typedef union u_vec2i
{
	t_v2i		v;
	struct
	{
		int			x;
		int			y;
	};
}	t_vec2i
__attribute__((aligned(16)));

/* Vector3d */

t_vec3d		v3d(double x, double y, double z);
bool		v3d_eq(t_vec3d v1, t_vec3d v2);

t_vec3d		v3d_add(const t_vec3d *v1, const t_vec3d *v2);
t_vec3d		v3d_sub(const t_vec3d *v1, const t_vec3d *v2);
t_vec3d		v3d_mult(const t_vec3d *v, double scalar);
t_vec3d		v3d_div(const t_vec3d *v, double scalar);

double		v3d_dot(const t_vec3d *v1, const t_vec3d *v2);
t_vec3d		v3d_cross(const t_vec3d *v1, const t_vec3d *v2);

double		v3d_len(const t_vec3d *v);
t_vec3d		v3d_norm(const t_vec3d *v);

t_vec3d		v3d_abs(const t_vec3d *v);
t_vec3d		v3d_inv(const t_vec3d *v);
t_vec3d		v3d_opp(const t_vec3d *v);
t_vec3d		v3d_min(const t_vec3d *v1, const t_vec3d *v2);
t_vec3d		v3d_max(const t_vec3d *v1, const t_vec3d *v2);
t_vec3d		v3d_mult_v3d(const t_vec3d *v1, const t_vec3d *v2);

bool		v3d_quadr(const t_vec3d *values, double *x1, double *x2);

t_vec3d		v3d_addmult(const t_vec3d *v1, const t_vec3d *v2, double scalar);
double		v3d_lensub(const t_vec3d *v1, const t_vec3d *v2);
t_vec3d		v3d_normsub(const t_vec3d *v1, const t_vec3d *v2);

t_vec2i		v3d_to_v2i(t_vec3d v);

/* Vector2i */

t_vec2i		v2i(int x, int y);
bool		v2i_eq(t_vec2i v1, t_vec2i v2);

# endif // __FT_MATH_VECTOR_H__
#endif // VECTOR_H
