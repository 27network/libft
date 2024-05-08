/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoi_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 09:51:35 by kiroussa          #+#    #+#             */
/*   Updated: 2024/05/08 14:31:42 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/string/parse.h>
#include <ft/string.h>
#include <limits.h>

/**
 * TODO: Make this function standalone
 */
static int	ft_check_base(char *base_str)
{
	int	i;
	int	j;

	if (ft_strlen(base_str) < 2)
		return (0);
	i = -1;
	while (base_str[++i])
	{
		j = i;
		while (base_str[++j])
			if (base_str[i] == base_str[j])
				return (0);
		if (base_str[i] == '+' || base_str[i] == '-')
			return (0);
		if (base_str[i] == ' ' || (base_str[i] >= 9 && base_str[i] <= 13))
			return (0);
	}
	return (1);
}

/**
 * TODO: Replace with strcspn
 */
static int	ft_get_index(char c, const char *base)
{
	int	i;

	i = -1;
	while (base[++i])
		if (c == base[i])
			return (i);
	return (-1);
}

static t_str_parseerr	ft_check_args(const char *str, const char *base)
{
	if (!str || !*str)
		return (PARSE_EMPTY);
	if (!base || !*base)
		return (PARSE_EMPTY);
	if (!ft_check_base((char *)base))
		return (PARSE_NOT_VALID_BASE);
	return (PARSE_SUCCESS);
}

t_str_parseerr	ft_strtoi_base(const char *str, const char *base, int *result)
{
	int				sign;
	long long		num;
	t_str_parseerr	err;

	sign = 1;
	num = 0;
	err = ft_check_args(str, base);
	if (err != PARSE_SUCCESS)
		return (err);
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
		sign = (*str++ == '-') * -2 + 1;
	if (ft_get_index(*str, base) == -1)
		return (PARSE_NOT_NUMBER);
	while (ft_get_index(*str, base) != -1)
	{
		num = num * ft_strlen(base) + ft_get_index(*str++, base);
		if (num > INT_MAX && sign == 1)
			return (PARSE_TOO_BIG);
		if (num > (long long)INT_MAX + 1 && sign == -1)
			return (PARSE_TOO_SMALL);
	}
	*result = (int)(num * sign);
	return (PARSE_SUCCESS * !*str + PARSE_NOT_NUMBER * *str);
}
