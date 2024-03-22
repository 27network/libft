/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_padding_mutator.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 04:16:21 by kiroussa          #+#    #+#             */
/*   Updated: 2024/03/22 18:45:14 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define FT_INTERNAL_ACCESS
#include <ft/internal/printf.h>

char	*pf_padding_mutator(t_fmt_spec *spec, char *str)
{
	char	*tmp;
	int		len;
	char	padding_char;
	char	sign;
	int		should_pad;

	len = ft_strlen(str);
	if (spec->width > len)
	{
		padding_char = ' ';
		should_pad = spec->flags & PF_ZERO_PAD;
		if (should_pad && spec->precision == -1 && spec->specifier != 's')
			padding_char = '0';
		sign = *str;
		if ((sign == '-' || sign == '+' || sign == ' ') && padding_char == '0')
			*str = padding_char;
		tmp = ft_strnew(spec->width);
		ft_memset(tmp, padding_char, spec->width);
		ft_memcpy(tmp + spec->width - len, str, len);
		if ((sign == '-' || sign == '+' || sign == ' ') && padding_char == '0')
			tmp[0] = sign;
		free(str);
		return (tmp);
	}
	return (str);
}
