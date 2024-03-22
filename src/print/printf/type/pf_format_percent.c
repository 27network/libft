/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_format_percent.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:17:57 by kiroussa          #+#    #+#             */
/*   Updated: 2024/03/22 18:45:13 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define FT_INTERNAL_ACCESS
#include <ft/internal/printf.h>

char	*pf_format_percent(t_fmt_spec *spec, va_list args)
{
	char	*str;

	(void)args;
	(void)spec;
	str = ft_calloc(2, sizeof(char));
	if (!str)
		return (NULL);
	str[0] = '%';
	return (str);
}
