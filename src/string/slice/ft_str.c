/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 16:51:29 by kiroussa          #+#    #+#             */
/*   Updated: 2024/04/10 16:57:22 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/string/slice.h>
#include <ft/string.h>

t_string	ft_str(const char *str)
{
	return ((t_string){.base = (char *) str, .length = ft_strlen(str)});
}
