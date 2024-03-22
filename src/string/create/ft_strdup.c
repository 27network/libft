/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 14:23:35 by kiroussa          #+#    #+#             */
/*   Updated: 2024/03/22 18:50:06 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/mem.h>
#include <ft/string.h>

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*buf;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	buf = ft_calloc(len + 1, sizeof(char));
	if (buf)
		ft_memcpy(buf, s, len);
	return (buf);
}
