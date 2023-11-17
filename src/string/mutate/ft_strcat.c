/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 02:31:00 by kiroussa          #+#    #+#             */
/*   Updated: 2023/11/05 02:31:08 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/string.h>

char	*ft_strcat(char *dest, const char *src)
{
	char	*dest_cpy;

	dest_cpy = dest + ft_strlen(dest);
	while (*src)
		*dest_cpy++ = *src++;
	*dest_cpy = '\0';
	return (dest);
}
