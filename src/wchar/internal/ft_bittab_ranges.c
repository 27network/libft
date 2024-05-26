/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bittab_ranges.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 20:38:55 by kiroussa          #+#    #+#             */
/*   Updated: 2024/05/23 21:00:04 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/wchar.h>

/**
 * @file ft_bittab_ranges.c
 * @brief This contains formulas to determine ranges of certain UTF-8 symbols
 *		  for decoding to multi-byte strings. 
 * @see https://emacs.stackexchange.com/q/33970
 */

uint32_t	ft_bittab_range(uint32_t a, uint32_t b)
{
	uint32_t	value;

	if (a == 0x80)
		value = 0x40u - b;
	else
		value = 0u - a;
	return (value << 23);
}

uint32_t	ft_bittab_c(uint32_t x)
{
	if (x < 2)
		return (-1);
	return (ft_bittab_range(0x80, 0xc0) | x);
}

uint32_t	ft_bittab_d(uint32_t x)
{
	return (ft_bittab_c((x + 16)));
}

uint32_t	ft_bittab_e(uint32_t x)
{
	if (x == 0)
		return (ft_bittab_range(0xa0, 0xc0));
	if (x == 0xd)
		return (ft_bittab_range(0x80, 0xa0));
	return (ft_bittab_range(0x80, 0xc0)
		| (ft_bittab_range(0x80, 0xc0) >> 6) | x);
}

uint32_t	ft_bittab_f(uint32_t x)
{
	if (x >= 5)
		return (0);
	if (x == 0)
		return (ft_bittab_range(0x90, 0xc0));
	if (x == 4)
		return (ft_bittab_range(0x80, 0x90));
	return (ft_bittab_range(0x80, 0xc0)
		| (ft_bittab_range(0x80, 0xc0) >> 6)
		| (ft_bittab_range(0x80, 0xc0) >> 12) | x);
}
