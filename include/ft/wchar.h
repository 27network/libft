/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wchar.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 16:52:28 by kiroussa          #+#    #+#             */
/*   Updated: 2024/03/10 17:09:59 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WCHAR_H
# define WCHAR_H

# include <stdint.h>
# include <wchar.h>

int			ft_mbtowc(wchar_t *restrict wc, const char *restrict src, size_t n);
uint32_t	*ft_multibyte_bittab(void);

#endif // WCHAR_H
