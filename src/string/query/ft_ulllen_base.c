/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulllen_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 02:49:21 by kiroussa          #+#    #+#             */
/*   Updated: 2024/06/27 03:20:34 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_ulllen_base(unsigned long long n, size_t base_size)
{
	size_t	size;

	size = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= base_size;
		size++;
	}
	return (size);
}
