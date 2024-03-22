/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_free_spec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 23:18:51 by kiroussa          #+#    #+#             */
/*   Updated: 2024/03/22 18:45:11 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define FT_INTERNAL_ACCESS
#include <ft/internal/printf.h>

t_fmt_spec	*pf_new_spec(
		const char *fmt,
		int *i,
		va_list args
) {
	t_fmt_spec	*spec;

	spec = pf_parse_spec(fmt, args);
	if (spec)
		*i += 1 + ft_strlen(spec->raw);
	return (spec);
}

void	pf_free_spec(t_fmt_spec *spec)
{
	free(spec->raw);
	free(spec->length);
	free(spec);
}
