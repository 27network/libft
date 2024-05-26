/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opt_msg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 23:10:29 by kiroussa          #+#    #+#             */
/*   Updated: 2024/05/23 00:16:18 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/opt.h>
#include <ft/print.h>
#include <unistd.h>

void	ft_opt_msg(const char *a, const char *b, const char *c, size_t size_c)
{
	const int	target_fd = STDERR_FILENO;

	ft_putstr_fd(a, target_fd);
	ft_putstr_fd(b, target_fd);
	(void) write(target_fd, c, size_c);
	ft_putchar_fd('\n', target_fd);
}
