/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_format_spec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 11:24:30 by kiroussa          #+#    #+#             */
/*   Updated: 2023/11/17 21:25:20 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/internal/printf.h>

static const t_type_formatter	g_formatters[] = {
['c'] = pf_format_char,
['s'] = pf_format_string,
['p'] = pf_format_pointer,
['d'] = pf_format_int,
['i'] = pf_format_int,
['u'] = pf_format_uint,
['x'] = pf_format_hex,
['X'] = pf_format_hex,
['%'] = pf_format_percent,
['n'] = pf_format_lenptr,
['m'] = pf_format_strerror,
};

static char	*pf_apply_flag_mutators(t_fmt_spec *spec, char *str)
{
	if (ft_strchr("sm", spec->specifier))
		str = pf_precision_mutator_str(spec, str);
	else if (ft_strchr("diuxX", spec->specifier))
		str = pf_precision_mutator_int(spec, str);
	if (spec->flags & PF_LEFT_JUSTIFY)
		str = pf_leftjustify_mutator(spec, str);
	if (!(spec->flags & PF_LEFT_JUSTIFY))
		str = pf_padding_mutator(spec, str);
	str = pf_hash_mutator_prefix(spec, str);
	return (str);
}

static char	*pf_apply_formatters(t_fmt_spec *spec, va_list args, int *hnc)
{
	t_type_formatter	formatter;
	char				*result;

	result = NULL;
	*hnc = 0;
	if (ft_strchr(PF_SPECIFIERS, spec->specifier))
	{
		formatter = g_formatters[(int)spec->specifier];
		if (formatter)
			result = formatter(spec, args);
		if (result && spec->specifier == 'c' && *result == '\0')
		{
			*hnc = 1;
			free(result);
			result = ft_strdup("a");
		}
	}
	return (result);
}

char	*pf_format_spec(t_fmt_spec *spec, va_list args, int *len)
{
	char	*formatted;
	int		has_null_char;

	*len = 0;
	formatted = pf_apply_formatters(spec, args, &has_null_char);
	if (formatted)
	{
		if (formatted && spec->specifier != '%')
			formatted = pf_apply_flag_mutators(spec, formatted);
		if (formatted)
			*len = ft_strlen(formatted);
		if (has_null_char)
			ft_strchr(formatted, 'a')[0] = '\0';
	}
	if (!formatted)
	{
		formatted = ft_strdup(spec->raw);
		if (formatted)
			*len = ft_strlen(formatted);
	}
	return (formatted);
}
