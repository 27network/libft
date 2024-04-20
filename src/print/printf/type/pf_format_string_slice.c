/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_format_string_slice.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:20:24 by kiroussa          #+#    #+#             */
/*   Updated: 2024/04/10 16:56:41 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define FT_INTERNAL_ACCESS
#include <ft/internal/printf.h>
#include <ft/string/slice.h>

char	*pf_format_string_slice(t_fmt_spec *spec, va_list args)
{
	t_string	slice;

	slice = *(t_string *)va_arg(args, t_string *);
	if (spec->precision >= 0 && (size_t)spec->precision < slice.length)
		slice.length = spec->precision;
	return (ft_strndup(slice.base, slice.length));
}
