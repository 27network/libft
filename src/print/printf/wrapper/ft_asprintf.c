/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_asprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 02:26:47 by kiroussa          #+#    #+#             */
/*   Updated: 2023/11/17 03:32:54 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/internal/printf.h>

int	ft_sprintf(char **str, const char *format, ...)
{
	va_list	args;
	int		len;

	va_start(args, format);
	len = ft_vasprintf(str, format, args);
	va_end(args);
	return (len);
}
