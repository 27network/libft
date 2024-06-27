/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 15:17:33 by kiroussa          #+#    #+#             */
/*   Updated: 2024/06/27 03:13:18 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/string.h>
#include <unistd.h>

int	ft_putstr_fd(const char *s, int fd)
{
	if (!s)
		s = "(null)";
	if (fd >= 0)
		return (write(fd, s, ft_strlen(s)));
	return (0);
}
