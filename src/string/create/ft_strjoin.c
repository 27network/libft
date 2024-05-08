/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 15:02:55 by kiroussa          #+#    #+#             */
/*   Updated: 2024/05/08 15:04:49 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/string.h>
#include <ft/mem.h>

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	new_length;
	char	*new_string;
	size_t	i;

	if (!s1)
		s1 = "";
	if (!s2)
		s2 = "";
	new_length = ft_strlen(s1) + ft_strlen(s2);
	new_string = ft_calloc(new_length + 1, sizeof(char));
	if (!new_string)
		return (NULL);
	i = 0;
	while (i++ < ft_strlen(s1))
		new_string[i - 1] = s1[i - 1];
	i = 0;
	while (i++ < ft_strlen(s2))
		new_string[ft_strlen(s1) + i - 1] = s2[i - 1];
	return (new_string);
}
