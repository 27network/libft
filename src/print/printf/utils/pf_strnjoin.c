/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 05:44:36 by kiroussa          #+#    #+#             */
/*   Updated: 2024/03/22 18:45:12 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define FT_INTERNAL_ACCESS
#include <ft/internal/printf.h>

char	*pf_strnjoin(char *s1, size_t n1, char *s2, size_t n2)
{
	char	*tmp;
	int		free_s1;
	int		free_s2;

	free_s1 = s1 == NULL;
	free_s2 = s2 == NULL;
	if (!s1)
		s1 = ft_strnew(n1);
	if (!s2)
		s2 = ft_strnew(n2);
	tmp = ft_strnew(n1 + n2);
	ft_memcpy(tmp, s1, n1);
	ft_memcpy(tmp + n1, s2, n2);
	if (free_s1)
		free(s1);
	if (free_s2)
		free(s2);
	return (tmp);
}
