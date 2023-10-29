/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 23:20:11 by kiroussa          #+#    #+#             */
/*   Updated: 2023/10/30 00:39:49 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	uint8_t	*ptr1;
	uint8_t	*ptr2;
	size_t	i;

	if (!s1 || !s2)
		return (s1);
	ptr1 = (uint8_t *)s1;
	ptr2 = (uint8_t *)s2;
	i = 0;
	if (s1 > s2)
		while (n--)
			ptr1[n] = ptr2[n];
	else
		while (i++ < n)
			ptr1[i - 1] = ptr2[i - 1];
	return (s1);
}
