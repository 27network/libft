/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 15:03:18 by kiroussa          #+#    #+#             */
/*   Updated: 2023/08/07 15:13:09 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_nbrlen(long long n)
{
	size_t	size;

	size = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = -n;
		size++;
	}
	while (n > 0)
	{
		n /= 10;
		size++;
	}
	return (size);
}

static void	ft_fill_number(char *str, size_t len, long long nbr)
{
	if (nbr > 9)
		ft_fill_number(str, len - 1, nbr / 10);
	str[len - 1] = nbr % 10 + '0';
}

char	*ft_itoa(int n)
{
	long long	nbr;
	size_t		str_len;
	char		*str;

	nbr = n;
	str_len = ft_nbrlen(nbr);
	str = malloc((str_len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[str_len] = 0;
	if (nbr < 0)
	{
		str[0] = '-';
		ft_fill_number(str + 1, str_len - 1, -nbr);
	}
	else
		ft_fill_number(str, str_len, nbr);
	return (str);
}
