/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v3d_addmult.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 23:31:41 by kiroussa          #+#    #+#             */
/*   Updated: 2024/11/07 00:01:35 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/math/vector.h>

__attribute__((always_inline))
t_vec3d	v3d_addmult(const t_vec3d *v1, const t_vec3d *v2, double scalar)
{
	return ((t_vec3d){.v = v1->v + (v2->v * scalar)});
}
