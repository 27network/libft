/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtolower.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 09:51:04 by kiroussa          #+#    #+#             */
/*   Updated: 2024/01/22 09:51:07 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/string.h>

char	*ft_strtolower(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (ft_isupper(str[i]))
			str[i] = ft_tolower(str[i]);
		i++;
	}
	return (str);
}
