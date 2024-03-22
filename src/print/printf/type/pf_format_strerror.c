/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_format_strerror.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 21:10:29 by kiroussa          #+#    #+#             */
/*   Updated: 2024/03/22 18:45:13 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _GNU_SOURCE
#define FT_INTERNAL_ACCESS
#include <ft/internal/printf.h>
#include <string.h>
#undef _GNU_SOURCE
#include <errno.h>

char	*pf_format_string0(t_fmt_spec *spec, char *str);

char	*pf_format_strerror(t_fmt_spec *spec, va_list args)
{
	(void)args;
	if (spec->flags & PF_HASH)
		return (pf_format_string0(spec, (char *)strerrorname_np(errno)));
	return (pf_format_string0(spec, strerror(errno)));
}
