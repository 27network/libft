/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 14:58:20 by kiroussa          #+#    #+#             */
/*   Updated: 2024/06/27 03:06:32 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/mem.h>

static int	ft_count_words(const char *str, char c)
{
	int		count;

	if (str == NULL)
		return (0);
	count = 0;
	while (*str)
	{
		while (*str && *str == c)
			str++;
		if (*str)
			count++;
		while (*str && *str != c)
			str++;
	}
	return (count);
}

static char	*ft_splitdup(const char *str, char c)
{
	int		length;
	char	*dest;
	char	*orig_dest;

	length = 0;
	while (str[length] && str[length] != c)
		length++;
	dest = ft_calloc(length + 1, sizeof(char));
	orig_dest = dest;
	if (dest != NULL)
	{
		while (*str && length)
		{
			*dest = *str;
			dest++;
			str++;
			length--;
		}
		*dest++ = '\0';
	}
	return (orig_dest);
}

char	**ft_split(const char *str, char c)
{
	char	**tab;
	int		i;

	tab = ft_calloc(ft_count_words(str, c) + 1, sizeof(char *));
	if (tab == NULL || str == NULL || !*str)
		return (tab);
	i = 0;
	while (*str)
	{
		while (*str && *str == c)
			str++;
		if (*str)
			tab[i++] = ft_splitdup(str, c);
		while (*str && *str != c)
			str++;
	}
	return (tab);
}
