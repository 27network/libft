/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strprepend.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 02:45:50 by kiroussa          #+#    #+#             */
/*   Updated: 2023/11/05 02:52:23 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/string.h>

void	ft_strprepend(char **s1, char *s2)
{
	char	*tmp;

	tmp = ft_strjoin(s2, *s1);
	ft_strdel(s1);
	*s1 = tmp;
}
