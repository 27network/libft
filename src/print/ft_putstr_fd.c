/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 15:17:33 by kiroussa          #+#    #+#             */
/*   Updated: 2023/11/17 02:53:17 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/print.h>
#include <ft/string.h>
#include <unistd.h>

void	ft_putstr_fd(int fd, const char *s)
{
	if (!s)
		s = "(null)";
	if (fd >= 0)
		write(fd, s, ft_strlen(s));
}
