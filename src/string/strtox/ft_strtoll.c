/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoll.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 02:08:36 by kiroussa          #+#    #+#             */
/*   Updated: 2024/05/19 03:55:48 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/string/parse.h>
#include <ft/string.h>
#include <limits.h>

static t_str_parseerr	check_overflow(long long old, long long new,
							int sign, int digit)
{
	t_str_parseerr	err;
	long long		max_old_allowed;

	(void)digit;
	err = PARSE_SUCCESS;
	if (sign == 1 && new < old)
		err = PARSE_TOO_BIG;
	if (sign == -1 && new > old)
		err = PARSE_TOO_SMALL;
	if (sign == 1)
		max_old_allowed = (LLONG_MAX - digit) / 10;
	else
		max_old_allowed = (LLONG_MIN + digit) / 10;
	if (sign == 1 && old > max_old_allowed)
		err = PARSE_TOO_BIG;
	if (sign == -1 && old < max_old_allowed)
		err = PARSE_TOO_SMALL;
	return (err);
}

static t_str_parseerr	fill_result(long long *res, const char *str,
							int sign)
{
	int				digit;
	long long		old_value;
	int				go_negative;
	t_str_parseerr	err;

	go_negative = 0;
	err = PARSE_SUCCESS;
	while (err == PARSE_SUCCESS && ft_isdigit(*str))
	{
		digit = *str++ - '0';
		old_value = *res;
		if (go_negative)
			*res = *res * 10 - digit;
		else
			*res = *res * 10 + digit;
		if (sign == -1 && go_negative == 0 && ++go_negative)
		{
			old_value *= sign;
			*res *= sign;
		}
		err = check_overflow(old_value, *res, sign, digit);
	}
	if (*str)
		return (PARSE_NOT_NUMBER);
	return (err);
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
	*result = num;
	return (PARSE_SUCCESS);
}
