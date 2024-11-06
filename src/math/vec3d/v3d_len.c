/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v3d_len.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 18:47:44 by kiroussa          #+#    #+#             */
/*   Updated: 2024/11/07 00:02:33 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/math/vector.h>
#include <math.h>

__attribute__((always_inline))
double	v3d_len(const t_vec3d *v)
{
	const t_v3d	result = v->v * v->v;

	return (sqrt(result[0] + result[1] + result[2]));
}
