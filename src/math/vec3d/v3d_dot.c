/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v3d_dot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 18:51:07 by kiroussa          #+#    #+#             */
/*   Updated: 2024/11/06 23:33:11 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/math/vector.h>

__attribute__((always_inline))
double	v3d_dot(t_vec3d *a, t_vec3d *b)
{
	const t_v4d	result = a->v * b->v;

	return (result[0] + result[1] + result[2]);
}
