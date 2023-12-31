/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 02:44:36 by kiroussa          #+#    #+#             */
/*   Updated: 2023/11/05 02:52:11 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/string.h>

void	ft_strappend(char **s1, char *s2)
{
	char	*tmp;

	tmp = ft_strjoin(*s1, s2);
	ft_strdel(s1);
	*s1 = tmp;
}
