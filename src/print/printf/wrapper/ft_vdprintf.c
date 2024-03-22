/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vdprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 02:27:01 by kiroussa          #+#    #+#             */
/*   Updated: 2024/03/22 18:45:12 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define FT_INTERNAL_ACCESS
#include <ft/internal/printf.h>

int	ft_vdprintf(int fd, const char *format, va_list args)
{
	char	*str;
	int		len;

	str = NULL;
	len = ft_vasprintf(&str, format, args);
	if (len > 0 && str)
		(void) write(fd, str, len);
	if (str)
		free(str);
	return (len);
}
