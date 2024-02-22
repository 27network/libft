/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec3d_mult.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 04:42:34 by kiroussa          #+#    #+#             */
/*   Updated: 2024/02/22 07:32:17 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/math/vector.h>

t_vec3d	ft_vec3d_mult(t_vec3d v, double scalar)
{
	t_vec3d	v_mult;

	v_mult.x = v.x * scalar;
	v_mult.y = v.y * scalar;
	v_mult.z = v.z * scalar;
	return (v_mult);
}
