/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 21:43:10 by kiroussa          #+#    #+#             */
/*   Updated: 2023/08/06 21:46:14 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief		Erases the data in the n bytes of the memory starting at the 
 * 				location pointed to by s, by writing zeros (bytes containing 
 * 				'\0') to that area.
 *
 * @param s		The memory area to erase.
 * @param n		The size of the memory area.
 *
 * @return void	Nothing.
 */
void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
