/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 21:50:14 by kiroussa          #+#    #+#             */
/*   Updated: 2023/08/07 11:21:25 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief			Copy bytes from memory area s2 into s1, stopping after the 
 * 					first occurrence of byte c (converted to an unsigned char) is 
 * 					copied, or after n bytes are copied, whichever comes first.
 *
 * @param s1		Pointer to the first memory area (the destination).
 * @param s2		Pointer to the second memory area (the source).
 * @param c			The character to stop the copy prostop the copy process.
 * @param n			The size to copy.
 *
 * @return void *	The target memory area provided in s1.
 */
void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	uint8_t	*ptr1;
	uint8_t	*ptr2;

	if (!s1 || !s2)
		return (NULL);
	ptr1 = (uint8_t *) s1;
	ptr2 = (uint8_t *) s2;
	while (n--)
	{
		*ptr1++ = *ptr2++;
		if (*(ptr2 - 1) == c)
			break ;
	}
	if (*(ptr2 - 1) == c)
		return (ptr1 - 1);
	return (NULL);
}
