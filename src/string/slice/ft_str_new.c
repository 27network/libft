/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 16:50:10 by kiroussa          #+#    #+#             */
/*   Updated: 2024/04/10 16:57:09 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/string/slice.h>

t_string	ft_str_new(const char *str, size_t length)
{
	return ((t_string){.base = (char *) str, .length = length});
}
