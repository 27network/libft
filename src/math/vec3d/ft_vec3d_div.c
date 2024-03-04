/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec3d_div.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 04:42:44 by kiroussa          #+#    #+#             */
/*   Updated: 2024/02/22 07:32:17 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/math/vector.h>

t_vec3d	ft_vec3d_div(t_vec3d v, double scalar)
{
	t_vec3d	v_div;

	v_div.x = v.x / scalar;
	v_div.y = v.y / scalar;
	v_div.z = v.z / scalar;
	return (v_div);
}
