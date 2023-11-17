/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 15:18:28 by kiroussa          #+#    #+#             */
/*   Updated: 2023/11/17 02:54:22 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/print.h>

void	ft_putendl_fd(int fd, const char *s)
{
	if (fd < 0)
		return ;
	if (!s)
		s = "(null)";
	ft_putstr_fd(fd, s);
	ft_putchar_fd(fd, '\n');
}
