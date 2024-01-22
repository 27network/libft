/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoupper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 09:50:34 by kiroussa          #+#    #+#             */
/*   Updated: 2024/01/22 09:50:58 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/string.h>

char	*ft_strtoupper(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (ft_islower(str[i]))
			str[i] = ft_toupper(str[i]);
		i++;
	}
	return (str);
}
