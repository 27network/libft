/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sincos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 22:50:47 by kiroussa          #+#    #+#             */
/*   Updated: 2024/11/17 16:26:10 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define __FT_FAST_MATH_STRUCTS
#include <ft/math.h>
#include <math.h>
#include <stddef.h>
#include <stdint.h>

static int	*ft_sine_table(void)
{
	static int		sine_table[16384 + 1];
	static int		init = 0;
	size_t			i;

	if (init == 0)
	{
		init = 1;
		i = 0;
		while (i < 16384)
		{
			sine_table[i] = (t_int_store){.f
				= sinf((double)i * M_PI * 2.0 / 65536.0)}.i;
			i++;
		}
	}
	return (sine_table);
}

float	__fastmath_lookup(int index)
{
	const int	*sine_table = ft_sine_table();
	int			neg;
	int			mask;
	int			pos;

	if (index == 32768)
		return ((t_int_store){.i = 0x250D3132}.f);
	neg = (index & 0x8000) << 16;
	mask = (index << 17) >> 31;
	pos = (0x8001 & mask) + (index ^ mask);
	pos &= 0x7fff;
	return (((t_int_store){.i = sine_table[pos] ^ neg}.f));
}

__attribute__((always_inline))
float	ft_sin(float f)
{
	return (__fastmath_lookup((int)(f * 10430.378f) & 0xFFFF));
}

__attribute__((always_inline))
float	ft_cos(float f)
{
	return (__fastmath_lookup((int)(f * 10430.378f + 16384.0) & 0xFFFF));
}
