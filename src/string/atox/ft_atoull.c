/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoull.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 22:23:18 by kiroussa          #+#    #+#             */
/*   Updated: 2024/06/27 03:05:58 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/string.h>

unsigned long long	ft_atoull(const char *nptr)
{
	long long	res;

	res = 0;
	while (ft_isspace(*nptr))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
		if (*nptr++ == '-')
			return (0);
	while (ft_isdigit(*nptr))
		res = res * 10 + (*nptr++ - '0');
	return (res);
}
