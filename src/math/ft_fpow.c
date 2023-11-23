/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fpow.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 22:35:53 by kiroussa          #+#    #+#             */
/*   Updated: 2023/11/23 22:37:38 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/math.h>

double	ft_fpow(double n, uint64_t pow)
{
	double	i;

	if (pow < 0)
		return (0);
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
