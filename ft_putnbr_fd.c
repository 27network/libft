/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 15:19:20 by kiroussa          #+#    #+#             */
/*   Updated: 2023/10/30 00:35:14 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int	is_min;

	if (fd < 0)
		return ;
	is_min = n == INT_MIN;
	if (is_min)
		n++;
	if (n < 0)
		ft_putchar_fd('-', fd);
	if (n < 0)
		n = -n;
	if (n > 9)
		ft_putnbr_fd(n / 10, fd);
	if (is_min)
		ft_putchar_fd((n % 10) + 1 + '0', fd);
	else
		ft_putchar_fd(n % 10 + '0', fd);
}
