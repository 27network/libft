/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_format_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:21:13 by kiroussa          #+#    #+#             */
/*   Updated: 2023/11/17 03:32:54 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/internal/printf.h>

char	*pf_format_char(t_fmt_spec *spec, va_list args)
{
	char	c;
	char	*str;

	(void)spec;
	c = va_arg(args, int);
	str = ft_calloc(2, sizeof(char));
	if (!str)
		return (NULL);
	str[0] = c;
	return (str);
}
