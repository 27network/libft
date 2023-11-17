/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 15:19:20 by kiroussa          #+#    #+#             */
/*   Updated: 2023/11/17 02:54:21 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/print.h>
#include <limits.h>

void	ft_putnbr_fd(int fd, long long n)
{
	int	is_min;

	if (fd < 0)
		return ;
	is_min = n == LLONG_MIN;
	if (is_min)
		n++;
	if (n < 0)
		ft_putchar_fd(fd, '-');
	if (n < 0)
		n = -n;
	if (n > 9)
		ft_putnbr_fd(fd, n / 10);
	if (is_min)
		ft_putchar_fd(fd, (n % 10) + 1 + '0');
	else
		ft_putchar_fd(fd, n % 10 + '0');
}
