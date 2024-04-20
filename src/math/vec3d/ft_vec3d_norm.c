/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec3d_norm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 18:46:53 by kiroussa          #+#    #+#             */
/*   Updated: 2024/04/20 18:55:28 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/math/vector.h>

t_vec3d	ft_vec3d_norm(t_vec3d v)
{
	double	len;

	len = ft_vec3d_len(v);
	if (len == 0)
		return (v);
	return (ft_vec3d_div(v, len));
}
