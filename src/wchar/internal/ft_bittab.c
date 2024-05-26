/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bittab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 20:48:06 by kiroussa          #+#    #+#             */
/*   Updated: 2024/05/23 21:21:35 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/mem.h>
#include <ft/wchar.h>

#define C ft_bittab_c
#define D ft_bittab_d
#define E ft_bittab_e
#define F ft_bittab_f
#define TAB_LEN 51

uint32_t	ft_bittab_c(uint32_t x);
uint32_t	ft_bittab_d(uint32_t x);
uint32_t	ft_bittab_e(uint32_t x);
uint32_t	ft_bittab_f(uint32_t x);

static void	ft_bittab_init(uint32_t *bittab)
{
	const uint32_t	straytab[TAB_LEN] = {
		C(0x2), C(0x3), C(0x4), C(0x5), C(0x6), C(0x7),
		C(0x8), C(0x9), C(0xa), C(0xb), C(0xc), C(0xd), C(0xe), C(0xf),
		D(0x0), D(0x1), D(0x2), D(0x3), D(0x4), D(0x5), D(0x6), D(0x7),
		D(0x8), D(0x9), D(0xa), D(0xb), D(0xc), D(0xd), D(0xe), D(0xf),
		E(0x0), E(0x1), E(0x2), E(0x3), E(0x4), E(0x5), E(0x6), E(0x7),
		E(0x8), E(0x9), E(0xa), E(0xb), E(0xc), E(0xd), E(0xe), E(0xf),
		F(0x0), F(0x1), F(0x2), F(0x3), F(0x4)
	};

	ft_memcpy(bittab, straytab, sizeof(straytab));
}

uint32_t	*ft_bittab(void)
{
	static uint32_t	bittab[TAB_LEN] = {0};
	static int		init = 0;

	if (!init)
	{
		ft_bittab_init(bittab);
		init = 1;
	}
	return (bittab);
}
