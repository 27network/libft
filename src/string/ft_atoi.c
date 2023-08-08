/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 11:57:41 by kiroussa          #+#    #+#             */
/*   Updated: 2023/08/08 13:57:24 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	long long	res;
	int			mult;

	res = 0;
	mult = 1;
	while (*nptr && (*nptr == ' ' || (*nptr >= 9 && *nptr <= 13)))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
		if (*nptr++ == '-')
			mult = -mult;
	while (*nptr && (*nptr >= '0' && *nptr <= '9'))
		res = res * 10 + (*nptr++ - '0');
	return (res * mult);
}
