/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_str_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 17:21:37 by kiroussa          #+#    #+#             */
/*   Updated: 2023/11/21 21:38:16 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/internal/printf.h>

void	pf_str_init(t_str *self, char *str, size_t length)
{
	if (!str)
		length = 0;
	self->inner = str;
	self->length = length;
}
