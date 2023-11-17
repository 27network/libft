/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_format_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 22:47:46 by kiroussa          #+#    #+#             */
/*   Updated: 2023/11/17 03:32:55 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/internal/printf.h>

char	*pf_format_pointer(t_fmt_spec *spec, va_list args)
{
	unsigned long long	n;
	char				*str;
	char				*tmp;

	(void) spec;
	n = va_arg(args, unsigned long long);
	if (n == 0)
		str = ft_strdup("(nil)");
	else
		str = ft_ulltoa_base(n, "0123456789abcdef");
	if (!str)
		return (NULL);
	if (str[0] == '(')
		return (str);
	if (spec->precision > (int) ft_strlen(str))
	{
		tmp = ft_strnew(spec->precision);
		ft_memset(tmp, '0', spec->precision);
		ft_memcpy(tmp + spec->precision - ft_strlen(str), str, ft_strlen(str));
		free(str);
		str = tmp;
	}
	tmp = ft_strjoin("0x", str);
	free(str);
	return (tmp);
}
