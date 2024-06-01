/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoins.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 14:42:56 by kiroussa          #+#    #+#             */
/*   Updated: 2024/06/01 21:59:07 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/mem.h>
#include <ft/string.h>
#include <stdarg.h>
#include <stdlib.h>

static char	*ft_strjoins0(size_t npos, char *sep, char **array,
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

static void	ft_strjoins_free(size_t npos,
		unsigned long long free_bitflag, va_list args)
{
	size_t	count;
	char	*tmp;

	count = -1;
	while (++count < npos)
	{
		if (free_bitflag & (1 << (npos - 1 - count)))
		{
			tmp = va_arg(args, char *);
			if (tmp)
				free(tmp);
		}
	}
}

static char	*ft_vstrjoins(size_t npos, char *sep,
		unsigned long long free_bitflag, va_list args)
{
	int		count;
	size_t	total_length;
	char	**array;
	char	*res;

	total_length = (npos - 1) * ft_strlen(sep);
	count = -1;
	array = ft_calloc(npos, sizeof(void *));
	if (!array)
		ft_strjoins_free(npos, free_bitflag, args);
	if (!array)
		return (NULL);
	while (++count < (int)npos)
	{
		array[count] = va_arg(args, char *);
		total_length += ft_strlen(array[count]);
	}
	res = ft_strjoins0(npos, sep, array, total_length);
	count = -1;
	while (++count < (int)npos)
		if (free_bitflag & (1 << (npos - 1 - count)) && array[count])
			free(array[count]);
	free(array);
	return (res);
}

char	*ft_strjoins(size_t npos, char *sep,
		unsigned long long free_bitflag, ...)
{
	va_list	args;
	char	*res;

	if (!sep)
		sep = "";
	va_start(args, free_bitflag);
	res = ft_vstrjoins(npos, sep, free_bitflag, args);
	va_end(args);
	return (res);
}
