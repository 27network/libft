/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_hash_mutator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 04:28:45 by kiroussa          #+#    #+#             */
/*   Updated: 2024/03/22 18:45:14 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define FT_INTERNAL_ACCESS
#include <ft/internal/printf.h>

static char	*pf_hex_prefix(char specifier)
{
	if (specifier == 'o')
		return ("0");
	else if (specifier == 'x')
		return ("0x");
	else if (specifier == 'X')
		return ("0X");
	return (NULL);
}

char	*pf_hash_mutator_prefix(t_fmt_spec *spec, char *str)
{
	char	*tmp;
	int		len;
	char	*prefix;

	len = ft_strlen(str);
	if (spec->flags & PF_HASH && pf_hex_prefix(spec->specifier))
	{
		if (*str == '0' && ft_strlen(str) == 1)
			return (str);
		prefix = pf_hex_prefix(spec->specifier);
		tmp = ft_strnew(len + ft_strlen(prefix));
		ft_memcpy(tmp, prefix, ft_strlen(prefix));
		ft_memcpy(tmp + ft_strlen(prefix), str, len);
		free(str);
		return (tmp);
	}
	return (str);
}
