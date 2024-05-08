/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_format_float.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 08:31:29 by kiroussa          #+#    #+#             */
/*   Updated: 2024/05/08 15:04:01 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define FT_INTERNAL_ACCESS
#include <ft/internal/printf.h>
#include <ft/math.h>
#include <ft/string/parse.h>
#include <ft/string.h>

/**
 * @brief      Converts a long double to a string.
 * @note       This is a very simple implementation, doesn't account for
 * 		   	   rounding, specific values, errors, etc.
 *
 * @param[in]  nbr        The number
 * @param[in]  precision  The precision
 *
 * @return     The string.
 */
static char	*ft_ftoa(long double nbr, int precision)
{
	char	*str;
	char	*tmp;
	int		i;

	str = ft_lltoa((int) nbr);
	tmp = ft_strjoins(2, "", 0b10, str, ".");
	nbr = nbr - (int)nbr;
	i = 0;
	while (i < precision)
	{
		nbr = nbr * 10;
		str = ft_lltoa(ft_abs((int) nbr));
		tmp = ft_strjoins(2, "", 0b11, tmp, str);
		nbr = nbr - (int)nbr;
		i++;
	}
	return (tmp);
}

char	*pf_format_float(t_fmt_spec *spec, va_list args)
{
	char	*str;
	double	nbr;

	nbr = va_arg(args, double);
	if (spec->precision == -1)
		spec->precision = 6;
	str = ft_ftoa(nbr, spec->precision);
	return (str);
}
