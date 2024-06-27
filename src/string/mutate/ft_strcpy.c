/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 02:26:16 by kiroussa          #+#    #+#             */
/*   Updated: 2024/06/27 03:08:55 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dest, const char *src)
{
	char	*dest_cpy;

	dest_cpy = dest;
	while (*src)
		*dest_cpy++ = *src++;
	*dest_cpy = '\0';
	return (dest);
}
