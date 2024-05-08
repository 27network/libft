/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 15:18:28 by kiroussa          #+#    #+#             */
/*   Updated: 2024/05/08 15:14:39 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/print.h>

void	ft_putendl_fd(const char *s, int fd)
{
	if (fd < 0)
		return ;
	if (!s)
		s = "(null)";
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}
