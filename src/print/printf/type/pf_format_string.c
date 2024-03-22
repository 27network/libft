/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_format_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:20:24 by kiroussa          #+#    #+#             */
/*   Updated: 2024/03/22 18:45:12 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define FT_INTERNAL_ACCESS
#include <ft/internal/printf.h>

char	*pf_format_string0(t_fmt_spec *spec, char *str)
{
	char	*new_str;
	char	*tmp;

	if (!str)
		str = "(null)";
	if (spec->precision >= 0 && (size_t)spec->precision < ft_strlen(str))
	{
		tmp = ft_substr(str, 0, spec->precision);
		new_str = ft_strdup(tmp);
		free(tmp);
	}
	else
		new_str = ft_strdup(str);
	return (new_str);
}

char	*pf_format_string(t_fmt_spec *spec, va_list args)
{
	return (pf_format_string0(spec, va_arg(args, char *)));
}
