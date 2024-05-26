/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mbtowc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 23:29:53 by kiroussa          #+#    #+#             */
/*   Updated: 2024/05/23 21:35:19 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define __FT_WCHAR_INTERNAL__
#include <ft/wchar.h>
#include <errno.h>
#include <stdlib.h>

static int	ft_mbtowc0(wchar_t *wc, const unsigned char *s, unsigned int c)
{
	if (ft_wchar_oob(c,*s))
		return (ft_illegal_sequence());
	c = c << 6 | *s++ - 0x80;
	if (!(c & (1U << 31)))
		return (*wc = c, 2);
	if (*s - 0x80u >= 0x40)
		return (ft_illegal_sequence());
	c = c << 6 | *s++ - 0x80;
	if (!(c & (1U << 31)))
		return (*wc = c, 3);
	if (*s - 0x80u >= 0x40)
		return (ft_illegal_sequence());
	*wc = c << 6 | *s++ - 0x80;
	return (4);
}

int	ft_mbtowc(wchar_t *wc, const char *str, size_t n)
{
	const unsigned char	*s = (const unsigned char *) str;
	unsigned int		c;
	wchar_t				dummy;

	if (!s)
		return (0);
	if (!n)
		return (ft_illegal_sequence());
	if (!wc)
		wc = &dummy;
	if (*s < 0x80)
		*wc = (wchar_t)(*s);
	if (*s < 0x80)
		return (!!*s);
	if (MB_CUR_MAX == 1)
		return ((*wc = ft_codeunit(*s)), 1);
	if ((*s - SA) > (SB - SA))
		return (ft_illegal_sequence());
	c = ft_bittab()[*s - SA];
	s++;
	if (n < 4 && ((c << (6 * n - 6)) & (1U << 31)))
		return (ft_illegal_sequence());
	return (ft_mbtowc0(wc, s, c));
}
