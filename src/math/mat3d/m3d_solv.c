/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m3d_solv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 00:48:35 by kiroussa          #+#    #+#             */
/*   Updated: 2024/11/18 00:48:39 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/math/matrix.h>

__attribute__((always_inline))
t_vec3d	m3d_solv(t_mat3d a, t_vec3d b)
{
	const t_mat3d	inv = m3d_inv(a);

	return (m3d_mult_v3d(inv, b));
}
