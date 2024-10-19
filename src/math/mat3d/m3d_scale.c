/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m3d_scale.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 01:43:36 by kiroussa          #+#    #+#             */
/*   Updated: 2024/10/19 02:21:51 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/math/matrix.h>
#include <ft/mem.h>

t_mat3d	m3d_scale(double sx, double sy, double sz)
{
	t_mat3d	matrix;

	ft_bzero(&matrix, sizeof(t_mat3d));
	matrix.m[0][0] = sx;
	matrix.m[1][1] = sy;
	matrix.m[2][2] = sz;
	return (matrix);
}
