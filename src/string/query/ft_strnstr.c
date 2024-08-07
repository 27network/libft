/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 00:17:29 by kiroussa          #+#    #+#             */
/*   Updated: 2024/06/27 03:16:29 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	k;

	if (little && !*little)
		return ((char *)big);
	if (len && big && little)
	{
		i = 0;
		while (i < len && big[i])
		{
			k = 0;
			while (big[i + k] && i + k < len)
			{
				if (little[k] != big[i + k])
					break ;
				k++;
				if (!little[k])
					return ((char *)big + i);
			}
			i++;
		}
	}
	return (NULL);
}
