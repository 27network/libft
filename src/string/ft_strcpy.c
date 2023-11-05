/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 02:26:16 by kiroussa          #+#    #+#             */
/*   Updated: 2023/11/05 02:26:58 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/string.h>

char	*ft_strcpy(char *dest, const char *src)
{
	char	*dest_cpy;

	dest_cpy = dest;
	while (*src)
		*dest_cpy++ = *src++;
	*dest_cpy = '\0';
	return (dest);
}
