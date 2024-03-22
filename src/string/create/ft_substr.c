/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 14:36:08 by kiroussa          #+#    #+#             */
/*   Updated: 2024/03/22 18:54:06 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/mem.h>
#include <ft/string.h>

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	length;
	size_t	new_length;
	char	*substr;

	if (!s)
		return (NULL);
	length = ft_strlen(s);
	if (start > length)
		return (ft_calloc(1, sizeof(char)));
	new_length = ft_strlen(s + start);
	if (new_length > len)
		new_length = len;
	substr = ft_calloc(new_length + 1, sizeof(char));
	if (!substr)
		return (NULL);
	while (new_length--)
		substr[new_length] = s[start + new_length];
	return (substr);
}
