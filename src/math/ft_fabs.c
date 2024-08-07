/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fabs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 22:35:09 by kiroussa          #+#    #+#             */
/*   Updated: 2024/06/27 03:22:29 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double	ft_fabs(double a)
{
	long long	i;

	i = *(long long *)&a;
	i &= ~(1ull << 63);
	return (*(double *) &i);
}
