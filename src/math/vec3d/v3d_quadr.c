/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v3d_quadr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 16:51:26 by kiroussa          #+#    #+#             */
/*   Updated: 2024/11/07 00:02:33 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/math/vector.h>
#include <math.h>

__attribute__((always_inline))
bool	v3d_quadr(const t_vec3d *values, double *x1, double *x2)
{
	const double	a = values->x;
	const double	b = values->y;
	const double	c = values->z;
	const double	delta = (b * b) - (4 * a * c);
	double			dsqrt;

	if (delta < 0)
		return (false);
	dsqrt = sqrt(delta);
	*x1 = (-b + dsqrt) / (2 * a);
	*x2 = (-b - dsqrt) / (2 * a);
	return (true);
}
