/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 11:57:41 by kiroussa          #+#    #+#             */
/*   Updated: 2024/06/27 03:05:36 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/string.h>

int	ft_atoi(const char *nptr)
{
	long long	res;
	int			mult;

	res = 0;
	mult = 1;
	while (ft_isspace(*nptr))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
		if (*nptr++ == '-')
			mult = -mult;
	while (ft_isdigit(*nptr))
		res = res * 10 + (*nptr++ - '0');
	return (res * mult);
}
