/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stpcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 02:27:11 by kiroussa          #+#    #+#             */
/*   Updated: 2023/11/05 02:29:16 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/string.h>

char	*ft_stpcpy(char *dest, const char *src)
{
	ft_strcpy(dest, src);
	return (dest + ft_strlen(src));
}
