/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v3d_div.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 04:42:44 by kiroussa          #+#    #+#             */
/*   Updated: 2024/10/19 02:21:49 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/math/vector.h>

t_vec3d	v3d_div(t_vec3d v, double scalar)
{
	t_vec3d	v_div;

	v_div.x = v.x / scalar;
	v_div.y = v.y / scalar;
	v_div.z = v.z / scalar;
	return (v_div);
}
