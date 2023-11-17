/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_format_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 22:58:06 by kiroussa          #+#    #+#             */
/*   Updated: 2023/11/17 03:32:54 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
