/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_leftjustify_mutator.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 04:06:29 by kiroussa          #+#    #+#             */
/*   Updated: 2024/03/22 18:45:14 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define FT_INTERNAL_ACCESS
#include <ft/internal/printf.h>

char	*pf_leftjustify_mutator(t_fmt_spec *spec, char *str)
{
	char	*tmp;
	int		len;

	len = ft_strlen(str);
	if (spec->width > len)
	{
		tmp = ft_strnew(spec->width);
		ft_memset(tmp, ' ', spec->width);
		ft_memcpy(tmp, str, len);
		free(str);
		return (tmp);
	}
	return (str);
}
