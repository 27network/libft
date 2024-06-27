/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 15:18:28 by kiroussa          #+#    #+#             */
/*   Updated: 2024/06/27 03:11:28 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/print.h>

int	ft_putendl_fd(const char *s, int fd)
{
	int	ret;

	if (fd < 0)
		return (0);
	if (!s)
		s = "(null)";
	ret = ft_putstr_fd(s, fd);
	if (ft_putchar_fd('\n', fd) == -1)
		return (-1);
	return (ret + 1);
}
