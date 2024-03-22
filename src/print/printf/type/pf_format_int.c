/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_format_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 22:56:43 by kiroussa          #+#    #+#             */
/*   Updated: 2024/03/22 18:45:13 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define FT_INTERNAL_ACCESS
#include <ft/internal/printf.h>

char	*pf_format_int(t_fmt_spec *spec, va_list args)
{
	long long	n;
	char		*str;
	char		*tmp;
	int			neg;

	n = va_arg(args, int);
	neg = n < 0;
	if (neg)
		n = -n;
	if (n == 0 && spec->precision == 0)
		str = ft_strdup("");
	else
		str = ft_lltoa(n);
	tmp = pf_prepend_sign(spec, str, neg);
	free(str);
	return (tmp);
}
