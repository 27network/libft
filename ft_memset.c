/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 21:34:31 by kiroussa          #+#    #+#             */
/*   Updated: 2023/10/30 00:40:02 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	uint8_t	*ptr;

	if (s)
	{
		ptr = (uint8_t *)s;
		while (n--)
			*ptr++ = c;
	}
	return (s);
}
