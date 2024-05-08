/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 02:08:36 by kiroussa          #+#    #+#             */
/*   Updated: 2024/05/08 14:31:36 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/string/parse.h>
#include <ft/string.h>
#include <limits.h>

t_str_parseerr	ft_strtoi(const char *str, int *result)
{
	int			sign;
	long long	num;

	sign = 1;
	num = 0;
	if (!str || !*str)
		return (PARSE_EMPTY);
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
		sign = (*str++ == '-') * -2 + 1;
	if (!ft_isdigit(*str))
		return (PARSE_NOT_NUMBER);
	while (ft_isdigit(*str))
	{
		num = num * 10 + (*str++ - '0');
		if (num > INT_MAX && sign == 1)
			return (PARSE_TOO_BIG);
		if (num > (long long)INT_MAX + 1 && sign == -1)
			return (PARSE_TOO_SMALL);
	}
	if (*str)
		return (PARSE_NOT_NUMBER);
	*result = (int)(num * sign);
	return (PARSE_SUCCESS);
}
