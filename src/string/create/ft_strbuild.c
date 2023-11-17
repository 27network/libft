/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strbuild.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 02:48:37 by kiroussa          #+#    #+#             */
/*   Updated: 2023/11/05 02:54:50 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/string.h>
#include <stdarg.h>

char	*ft_strbuild(size_t n, ...)
{
	va_list	ap;
	char	*str;

	va_start(ap, n);
	str = ft_strnew(0);
	while (n--)
		ft_strappend(&str, va_arg(ap, char *));
	va_end(ap);
	return (str);
}
