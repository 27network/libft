/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 02:54:52 by kiroussa          #+#    #+#             */
/*   Updated: 2024/06/27 03:06:32 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/mem.h>

static int	ft_is_charset(char c, const char *charset)
{
	int	i;

	if (charset == NULL)
		return (0);
	i = -1;
	while (charset[++i])
		if (c == charset[i])
			return (1);
	return (0);
}

static int	ft_count_words(const char *str, const char *charset)
{
	int		count;

	if (str == NULL)
		return (0);
	if (charset == NULL)
		return (1);
	count = 0;
	while (*str)
	{
		while (*str && ft_is_charset(*str, charset))
			str++;
		if (*str)
			count++;
		while (*str && !ft_is_charset(*str, charset))
			str++;
	}
	return (count);
}

static char	*ft_splitdup(const char *str, const char *charset)
{
	int		length;
	char	*dest;
	char	*orig_dest;

	length = 0;
	while (str[length] && !ft_is_charset(str[length], charset))
		length++;
	dest = ft_calloc(length + 1, sizeof(char));
	orig_dest = dest;
	if (dest)
	{
		while (*str && length)
		{
			*dest = *str;
			dest++;
			str++;
			length--;
		}
	}
	return (orig_dest);
}

char	**ft_splits(const char *str, const char *charset)
{
	char	**tab;
	int		i;

	tab = ft_calloc(ft_count_words(str, charset) + 1, sizeof(char *));
	if (tab == NULL || str == NULL || !*str)
		return (tab);
	if (charset == NULL || !*charset)
	{
		tab[0] = ft_splitdup(str, charset);
		return (tab);
	}
	i = 0;
	while (*str)
	{
		while (*str && ft_is_charset(*str, charset))
			str++;
		if (*str)
			tab[i++] = ft_splitdup(str, charset);
		while (*str && !ft_is_charset(*str, charset))
			str++;
	}
	return (tab);
}
