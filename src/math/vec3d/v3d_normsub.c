/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v3d_normsub.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 23:37:33 by kiroussa          #+#    #+#             */
/*   Updated: 2024/11/07 00:54:36 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/math/vector.h>

__attribute__((always_inline))
t_vec3d	v3d_normsub(const t_vec3d *v, const t_vec3d *v2)
{
	const t_vec3d	v3 = v3d_sub(v, v2);
	const double	len = v3d_len(&v3);

	if (len != 0)
		return ((t_vec3d){.v = v3.v / len});
	return ((t_vec3d){.v = v3.v});
}
