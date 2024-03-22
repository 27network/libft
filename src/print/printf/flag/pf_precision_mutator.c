/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_precision_mutator.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 03:57:51 by kiroussa          #+#    #+#             */
/*   Updated: 2024/03/22 18:45:13 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define FT_INTERNAL_ACCESS
#include <ft/internal/printf.h>

char	*pf_precision_mutator_str(t_fmt_spec *spec, char *str)
{
	char	*tmp;
	int		len;

	len = ft_strlen(str);
	if (spec->precision != -1 && spec->precision < len)
	{
		tmp = ft_strnew(spec->precision);
		ft_memcpy(tmp, str, spec->precision);
		free(str);
		return (tmp);
	}
	return (str);
}

char	*pf_precision_mutator_int(t_fmt_spec *spec, char *str)
{
	char	*tmp;
	int		len;
	char	sign;
	int		is_sign;

	sign = *str;
	is_sign = (sign == '+' || sign == '-' || sign == ' ');
	len = ft_strlen(str) - is_sign;
	if (spec->precision > len)
	{
		tmp = ft_strnew(spec->precision + is_sign);
		ft_memset(tmp + is_sign, '0', spec->precision);
		ft_memcpy(tmp + is_sign + spec->precision - len, str + is_sign, len);
		if (is_sign)
			tmp[0] = sign;
		free(str);
		return (tmp);
	}
	return (str);
}
