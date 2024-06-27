/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 23:04:11 by kiroussa          #+#    #+#             */
/*   Updated: 2024/06/27 03:05:47 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/string.h>

static int	ft_check_base(const char *base_str)
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

static int	ft_get_index(char c, const char *base)
{
	int	i;

	i = -1;
	while (base[++i])
		if (c == base[i])
			return (i);
	return (-1);
}

int	ft_atoi_base(const char *str, const char *base)
{
	int	i;
	int	nb;
	int	sign;
	int	base_len;

	i = 0;
	nb = 0;
	sign = 1;
	base_len = ft_strlen(base);
	if (!ft_check_base(base))
		return (0);
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (ft_get_index(str[i], base) == -1)
	{
		if (str[i] == '-')
			sign *= -1;
		else if (str[i] != '+')
			return (0);
		i++;
	}
	while (ft_get_index(str[i++], base) != -1)
		nb = nb * base_len + ft_get_index(str[i - 1], base);
	return (nb * sign);
}
