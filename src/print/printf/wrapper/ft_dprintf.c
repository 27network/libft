/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 02:26:30 by kiroussa          #+#    #+#             */
/*   Updated: 2023/11/17 03:29:27 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/internal/printf.h>

int	ft_dprintf(int fd, const char *format, ...)
{
	va_list	args;
	int		len;

	va_start(args, format);
	len = ft_vdprintf(fd, format, args);
	va_end(args);
	return (len);
}
