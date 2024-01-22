/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fpow.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 22:35:53 by kiroussa          #+#    #+#             */
/*   Updated: 2024/01/22 08:23:58 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/math.h>

double	ft_fpow(double n, uint64_t pow)
{
	double	i;

	if (!pow)
		return (1);
	if (!n)
		return (0);
	i = n;
	pow--;
	while (pow--)
		n *= i;
	return (n);
}
