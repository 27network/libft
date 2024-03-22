/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_str_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 17:22:28 by kiroussa          #+#    #+#             */
/*   Updated: 2024/03/22 18:47:47 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define FT_INTERNAL_ACCESS
#include <ft/internal/printf.h>

t_str	*pf_str_create(char *string, size_t length)
{
	t_str	*str;

	str = (t_str *)ft_calloc(1, sizeof(t_str));
	if (!str)
		return (NULL);
	pf_str_init(str, string, length);
	return (str);
}
