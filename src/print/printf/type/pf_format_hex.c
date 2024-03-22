/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_format_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 22:58:06 by kiroussa          #+#    #+#             */
/*   Updated: 2024/03/22 18:45:13 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define FT_INTERNAL_ACCESS
#include <ft/internal/printf.h>

char	*pf_format_hex(t_fmt_spec *spec, va_list args)
{
	unsigned int	n;
	char			*str;
	char			*base;

	base = "0123456789abcdef";
	if (spec->specifier == 'X')
		base = "0123456789ABCDEF";
	n = va_arg(args, unsigned int);
	if (n == 0 && spec->precision == 0)
		str = ft_strdup("");
	else
		str = ft_ulltoa_base(n, base);
	return (str);
}
