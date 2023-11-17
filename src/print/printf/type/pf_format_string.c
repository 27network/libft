/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_format_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:20:24 by kiroussa          #+#    #+#             */
/*   Updated: 2023/11/17 03:32:55 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/internal/printf.h>

char	*pf_format_string(t_fmt_spec *spec, va_list args)
{
	char	*str;
	char	*formatted;

	str = va_arg(args, char *);
	if (!str && (spec->precision == -1 || spec->precision >= 6))
		str = "(null)";
	else if (!str)
		str = "";
	if (spec->precision >= 0 && (size_t)spec->precision < ft_strlen(str))
		formatted = ft_substr(str, 0, spec->precision);
	else
		formatted = ft_strdup(str);
	return (formatted);
}
