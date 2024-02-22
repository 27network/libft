/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 14:42:56 by kiroussa          #+#    #+#             */
/*   Updated: 2024/02/22 23:23:20 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/mem.h>
#include <ft/string.h>
#include <stdarg.h>
#include <stdlib.h>

static char	*ft_strjoin0(size_t npos, char *sep, char **array,
		size_t total_length)
{
	char	*res;
	size_t	count;
	size_t	strptr;
	size_t	len;
	size_t	len_sep;

	res = ft_calloc(total_length + 1, sizeof(char));
	if (!res)
		return (NULL);
	count = 0;
	strptr = 0;
	len_sep = ft_strlen(sep);
	while (count < npos)
	{
		len = ft_strlen(array[count]);
		ft_memcpy(res + strptr, array[count], len);
		count++;
		strptr += len;
		if (count != npos)
			ft_memcpy(res + strptr, sep, len_sep);
		if (count != npos)
			strptr += len_sep;
	}
	return (res);
}

static char	*ft_vstrjoin(size_t npos, char *sep,
		unsigned long long free_bitflag, va_list args)
{
	size_t	count;
	size_t	total_length;
	char	**array;
	char	*res;

	total_length = (npos - 1) * ft_strlen(sep);
	count = 0;
	array = ft_calloc(npos, sizeof(void *));
	if (!array)
		return (NULL);
	while (count++ < npos)
	{
		array[count - 1] = va_arg(args, char *);
		total_length += ft_strlen(array[count - 1]);
	}
	res = ft_strjoin0(npos, sep, array, total_length);
	count = 0;
	while (count < npos)
	{
		if (free_bitflag & (1 << (npos - 1 - count)))
			free(array[count]);
		count++;
	}
	free(array);
	return (res);
}

char	*ft_strjoin(size_t npos, char *sep,
		unsigned long long free_bitflag, ...)
{
	va_list	args;
	char	*res;

	va_start(args, free_bitflag);
	res = ft_vstrjoin(npos, sep, free_bitflag, args);
	va_end(args);
	return (res);
}
