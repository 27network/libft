/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec3d_len.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 18:47:44 by kiroussa          #+#    #+#             */
/*   Updated: 2024/04/20 18:56:41 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/math/vector.h>
#include <math.h>

double	ft_vec3d_len(t_vec3d v)
{
	return (sqrt(v.x * v.x + v.y * v.y + v.z * v.z));
}
