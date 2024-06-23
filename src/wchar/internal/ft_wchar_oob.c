/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchar_oob.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 21:02:32 by kiroussa          #+#    #+#             */
/*   Updated: 2024/05/23 21:12:47 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/wchar.h>

int	ft_wchar_oob(unsigned int c, unsigned char b)
{
	return (((((b) >> 3) - 0x10) | (((b) >> 3) + ((int32_t)(c) >> 26))) & ~7);
}