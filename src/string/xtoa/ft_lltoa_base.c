/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 15:03:18 by kiroussa          #+#    #+#             */
/*   Updated: 2024/05/08 15:08:34 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/mem.h>
#include <ft/string.h>

static void	ft_fill_number(
		char *str,
		const char *base,
		size_t len,
		long long nbr
) {
	if (nbr >= (long long)ft_strlen(base))
		ft_fill_number(str, base, len - 1, nbr / ft_strlen(base));
	str[len - 1] = base[nbr % ft_strlen(base)];
}

char	*ft_lltoa_base(long long n, const char *base)
{
	long long	nbr;
	size_t		nb_len;
	char		*str;

	nbr = n;
	nb_len = ft_lllen_base(nbr, ft_strlen(base));
	str = ft_calloc(nb_len + 1, sizeof(char));
	if (!str)
		return (NULL);
	if (nbr < 0)
		str[0] = '-';
	if (nbr < 0)
		ft_fill_number(str + 1, base, nb_len - 1, -nbr);
	else
		ft_fill_number(str, base, nb_len, nbr);
	return (str);
}

char	*ft_itoa_base(int n, const char *base)
			__attribute__((weak, alias("ft_lltoa_base")));
