/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 02:46:24 by kiroussa          #+#    #+#             */
/*   Updated: 2023/11/05 02:46:30 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/string.h>

char	*ft_strndup(const char *s1, size_t n)
{
	char	*str;
	size_t	i;

	str = ft_strnew(n);
	if (str)
	{
		i = 0;
		while (i < n)
		{
			str[i] = s1[i];
			i++;
		}
	}
	return (str);
}
