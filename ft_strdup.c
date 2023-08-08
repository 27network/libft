/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 14:23:35 by kiroussa          #+#    #+#             */
/*   Updated: 2023/08/07 14:25:36 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*buf;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	buf = malloc((len + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	buf[len] = 0;
	while (len--)
		buf[len] = s[len];
	return (buf);
}
