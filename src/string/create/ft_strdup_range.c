/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_range.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 02:46:47 by kiroussa          #+#    #+#             */
/*   Updated: 2023/11/05 02:47:00 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/string.h>

char	*ft_strdup_range(const char *s1, size_t start, size_t end)
{
	char	*str;
	int		i;

	if (!s1)
		return (NULL);
	str = ft_strnew(end - start + 1);
	if (str)
	{
		i = 0;
		while (start <= end)
			str[i++] = s1[start++];
	}
	return (str);
}
