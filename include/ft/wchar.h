/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wchar.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 23:30:09 by kiroussa          #+#    #+#             */
/*   Updated: 2024/05/25 01:11:37 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WCHAR_H
# define WCHAR_H
# undef WCHAR_H
# ifndef __FT_WCHAR_H__
#  define __FT_WCHAR_H__

#  include <stdint.h>
#  include <wchar.h>

int			ft_mbtowc(wchar_t *pwc, const char *s, size_t n);
int			ft_mblen(const char *s, size_t n);

#  ifdef __FT_WCHAR_INTERNAL__

#   define SA 0xc2u
#   define SB 0xf4u

wchar_t		ft_codeunit(unsigned char c);
int			ft_wchar_oob(unsigned int c, unsigned char b);
uint32_t	*ft_bittab(void);

int			ft_illegal_sequence(void);

#  endif // __FT_WCHAR_INTERNAL__

# endif // __FT_WCHAR_H__
#endif // WCHAR_H
