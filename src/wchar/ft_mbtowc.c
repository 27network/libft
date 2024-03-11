/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mbtowc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 16:51:57 by kiroussa          #+#    #+#             */
/*   Updated: 2024/03/10 17:10:02 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/wchar.h>
#include <errno.h>

static int	_mbtowc_inner(
	wchar_t *restrict wc,
	unsigned int c,
	const unsigned char *s
) {
	if (!(c & (1U << 31)))
		*wc = c;
	if (!(c & (1U << 31)))
		return (2);
	if (*s - 0x80u >= 0x40)
		return (-1);
	c = c << 6 | *s++ - 0x80;
	if (!(c & (1U << 31)))
		*wc = c;
	if (!(c & (1U << 31)))
		return (3);
	if (*s - 0x80u >= 0x40)
		return (-1);
	*wc = c << 6 | *s++ - 0x80;
	return (4);
}

static int	_mbtowc_prechecks(
	wchar_t *restrict wc,
	const char *restrict src,
	size_t n
) {
	unsigned int		c;
	const unsigned char	*s;

	s = (const unsigned char *) src;
	if (!s)
		return (0);
	if (!n)
		return (-1);
	if (!wc)
		wc = (void *)&wc;
	if (*s < 0x80)
		return (!!(*wc = *s));
	if (*s - 0xc2u > 0xf4u - 0xc2u)
		return (-1);
	c = ft_multibyte_bittab()[*s++ - 0xc2u];
	if (n < 4 && ((c << (6 * n - 6)) & (1U << 31)))
		return (-1);
	if (((((*s) >> 3) - 0x10) | (((*s) >> 3) + ((int32_t)(c) >> 26))) & ~7)
		return (-1);
	c = c << 6 | *s++ - 0x80;
	return (_mbtowc_inner(wc, c, s));
}

int	ft_mbtowc(wchar_t *restrict wc, const char *restrict src, size_t n)
{
	int	ret;

	ret = _mbtowc_prechecks(wc, src, n);
	if (ret == -1)
		errno = EILSEQ;
	return (ret);
}
