/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v3d_norm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 18:46:53 by kiroussa          #+#    #+#             */
/*   Updated: 2024/11/07 00:02:33 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/math/vector.h>

__attribute__((always_inline))
t_vec3d	v3d_norm(const t_vec3d *v)
{
	double	len;

	len = v3d_len(v);
	if (len != 0)
		return ((t_vec3d){.v = v->v / len});
	return ((t_vec3d){.v = v->v});
}
