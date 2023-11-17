/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_str_append.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 17:23:41 by kiroussa          #+#    #+#             */
/*   Updated: 2023/11/17 03:32:55 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/internal/printf.h>

t_str	*pf_str_append(t_str *self, t_str *other)
{
	char	*new_inner;
	size_t	new_length;

	if (!self || !other)
		return (NULL);
	if (!self->inner)
		self->inner = ft_strdup("");
	if (!other->inner)
		other->inner = ft_strdup("");
	new_length = self->length + other->length;
	new_inner = ft_strnew(new_length);
	if (!new_inner)
		return (NULL);
	ft_memcpy(new_inner, self->inner, self->length);
	ft_memcpy(new_inner + self->length, other->inner, other->length);
	free(self->inner);
	self->inner = new_inner;
	self->length = new_length;
	free(other->inner);
	free(other);
	return (self);
}
