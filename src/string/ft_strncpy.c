/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 02:30:27 by kiroussa          #+#    #+#             */
/*   Updated: 2023/11/05 02:30:33 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/string.h>

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	char	*dest_cpy;

	dest_cpy = dest;
	while (*src && n--)
		*dest_cpy++ = *src++;
	while (n--)
		*dest_cpy++ = '\0';
	return (dest);
}
