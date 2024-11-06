/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v3d_norm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 18:46:53 by kiroussa          #+#    #+#             */
/*   Updated: 2024/11/06 23:33:12 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/math/vector.h>

__attribute__((always_inline))
t_vec3d	v3d_norm(t_vec3d *v)
{
	double	len;

	len = v3d_len(v);
	if (len == 0)
		return ((t_vec3d){.v = v->v});
	return (v3d_div(v, len));
}