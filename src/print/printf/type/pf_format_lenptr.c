/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_format_lenptr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 21:18:07 by kiroussa          #+#    #+#             */
/*   Updated: 2024/03/22 18:45:13 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define FT_INTERNAL_ACCESS
#include <ft/internal/printf.h>

char	*pf_format_lenptr(t_fmt_spec *spec, va_list args)
{
	int	*ptr;

	ptr = va_arg(args, int *);
	if (ptr)
		*ptr = spec->_current_length;
	spec->width = 0;
	spec->precision = -1;
	return (ft_strdup(""));
}
