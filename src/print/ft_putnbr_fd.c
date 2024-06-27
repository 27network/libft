/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 15:19:20 by kiroussa          #+#    #+#             */
/*   Updated: 2024/06/27 03:14:26 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/print.h>
#include <limits.h>

int	ft_putnbr_fd(long long n, int fd)
{
	int	ret;

	if (n == LLONG_MIN)
		return (ft_putstr_fd("-9223372036854775808", fd));
	ret = 0;
	if (n < 0)
	{
		ret += ft_putchar_fd('-', fd);
		if (ret == -1)
			return (-1);
		n = -n;
	}
	if (n >= 10)
		ret += ft_putnbr_fd(n / 10, fd);
	ret += ft_putchar_fd(n % 10 + '0', fd);
	return (ret);
}
