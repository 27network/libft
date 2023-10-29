/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 21:46:29 by kiroussa          #+#    #+#             */
/*   Updated: 2023/10/30 00:39:42 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *s1, const void *s2, size_t n)
{
	uint8_t	*ptr1;
	uint8_t	*ptr2;

	if (s1 && s2)
	{
		ptr1 = (uint8_t *)s1;
		ptr2 = (uint8_t *)s2;
		while (n--)
			*ptr1++ = *ptr2++;
	}
	return (s1);
}
