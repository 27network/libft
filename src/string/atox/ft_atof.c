/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 22:24:26 by kiroussa          #+#    #+#             */
/*   Updated: 2024/06/27 03:05:31 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/math.h>
#include <ft/string/parse.h>
#include <ft/string.h>

static double	after_dot_part(const char *nptr)
{
	double	res;
	int		mult;

	res = 0;
	mult = 1;
	while (ft_isdigit(*nptr))
	{
		res = res * 10 + (*nptr++ - '0');
		mult /= 10;
	}
	return (res * mult);
}

double	ft_atof(const char *nptr)
{
	double	res;
	int		mult;

	res = 0;
	mult = 1;
	while (ft_isspace(*nptr))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
		if (*nptr++ == '-')
			mult = -mult;
	while (ft_isdigit(*nptr))
		res = res * 10 + (*nptr++ - '0');
	if (*nptr == '.')
		res += after_dot_part(++nptr);
	if (*nptr == 'e' || *nptr == 'E')
		res *= ft_pow(10, ft_atoi(++nptr));
	return (res * mult);
}
