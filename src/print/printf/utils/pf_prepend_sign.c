/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_prepend_sign.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 03:44:36 by kiroussa          #+#    #+#             */
/*   Updated: 2024/05/08 15:04:27 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define FT_INTERNAL_ACCESS
#include <ft/internal/printf.h>

char	*pf_prepend_sign(t_fmt_spec *spec, char *str, int neg)
{
	char	*sign;
	char	*tmp;

	if (neg)
		sign = ft_strdup("-");
	else if (spec->flags & PF_PLUS)
		sign = ft_strdup("+");
	else if (spec->flags & PF_SPACE)
		sign = ft_strdup(" ");
	else
		return (ft_strdup(str));
	tmp = ft_strjoins(2, "", 0b10, sign, str);
	return (tmp);
}
