/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v3d_lensub.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 23:46:55 by kiroussa          #+#    #+#             */
/*   Updated: 2024/11/07 00:02:33 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <ft/math/vector.h>

__attribute__((always_inline))
double	v3d_lensub(const t_vec3d *v1, const t_vec3d *v2)
{
	const t_v3d	prev = v1->v - v2->v;
	const t_v3d	result = prev * prev;

	return (sqrt(result[0] + result[1] + result[2]));
}
