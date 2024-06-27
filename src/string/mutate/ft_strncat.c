/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 02:34:06 by kiroussa          #+#    #+#             */
/*   Updated: 2024/06/27 03:15:54 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	char	*dest_cpy;

	dest_cpy = dest;
	while (*dest_cpy)
		dest_cpy++;
	while (*src && n--)
		*dest_cpy++ = *src++;
	*dest_cpy = '\0';
	return (dest);
}
