/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 02:54:52 by kiroussa          #+#    #+#             */
/*   Updated: 2023/11/17 03:12:07 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/string.h>
#include <stdlib.h>

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
	dest = malloc(length + 1);
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

char	**ft_splits(const char *str, const char *charset)
{
	char	**tab;
	int		i;

	tab = malloc((ft_count_words(str, charset) + 1) * sizeof(char *));
	if (tab == NULL)
		return (tab);
	tab[ft_count_words(str, charset)] = NULL;
	if (str == NULL || !*str)
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
