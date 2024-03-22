/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_format_uint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:24:08 by kiroussa          #+#    #+#             */
/*   Updated: 2024/03/22 18:45:12 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define FT_INTERNAL_ACCESS
#include <ft/internal/printf.h>

char	*pf_format_uint(t_fmt_spec *spec, va_list args)
{
	unsigned int	n;
	char			*str;

	n = va_arg(args, unsigned int);
	if (n == 0 && spec->precision == 0)
		str = ft_strdup("");
	else
		str = ft_ulltoa(n);
	return (str);
}
