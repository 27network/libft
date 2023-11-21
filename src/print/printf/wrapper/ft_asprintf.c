/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_asprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 02:26:47 by kiroussa          #+#    #+#             */
/*   Updated: 2023/11/21 05:13:19 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/internal/printf.h>

int	ft_asprintf(char **str, const char *format, ...)
{
	va_list	args;
	int		len;

	va_start(args, format);
	len = ft_vasprintf(str, format, args);
	va_end(args);
	return (len);
}
