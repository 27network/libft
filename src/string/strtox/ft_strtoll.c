/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoll.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 02:08:36 by kiroussa          #+#    #+#             */
/*   Updated: 2024/05/17 18:06:09 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/string/parse.h>
#include <ft/string.h>
#include <limits.h>

static t_str_parseerr	fill_result(long long *res, const char *str, int sign)
{
	int			digit;
	long long	max_possible;
	long long	min_possible;
	long long	old_value;

	while (ft_isdigit(*str))
	{
		digit = *str++ - '0';
		max_possible = LLONG_MAX / 10 - digit;
		min_possible = LLONG_MIN / 10 + digit;
		if (*res > max_possible)
			return (PARSE_TOO_BIG);
		if (*res < min_possible)
			return (PARSE_TOO_SMALL);
		old_value = *res;
		*res = *res * 10 + digit;
		if (*res < old_value && sign == 1)
			return (PARSE_TOO_BIG);
		if (*res > old_value && sign == -1)
			return (PARSE_TOO_SMALL);
	}
	if (*str)
		return (PARSE_NOT_NUMBER);
	return (PARSE_SUCCESS);
}

t_str_parseerr	ft_strtoll(const char *str, long long *result)
{
	int				sign;
	long long		num;
	t_str_parseerr	err;

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
	err = fill_result(&num, str, sign);
	if (err != PARSE_SUCCESS)
		return (err);
	if (num == LLONG_MIN && sign == -1)
		return (PARSE_TOO_SMALL);
	*result = num * sign;
	return (PARSE_SUCCESS);
}
