/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 15:17:33 by kiroussa          #+#    #+#             */
/*   Updated: 2024/05/08 15:13:30 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/print.h>
#include <ft/string.h>
#include <unistd.h>

void	ft_putstr_fd(const char *s, int fd)
{
	if (!s)
		s = "(null)";
	if (fd >= 0)
		(void)write(fd, s, ft_strlen(s));
}
