/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_str_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 17:22:28 by kiroussa          #+#    #+#             */
/*   Updated: 2023/11/17 03:32:55 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/internal/printf.h>

t_str	*pf_str_create(char *string, size_t length)
{
	t_str	*str;

	str = (t_str *)malloc(sizeof(t_str));
	if (!str)
		return (NULL);
	pf_str_init(str, string, length);
	return (str);
}
