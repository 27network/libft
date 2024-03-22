/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 15:03:18 by kiroussa          #+#    #+#             */
/*   Updated: 2024/03/22 18:54:50 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/mem.h>
#include <ft/string.h>

static void	ft_fill_number(
		char *str,
		const char *base,
		size_t len,
		unsigned long long nbr
) {
	if (nbr >= (unsigned long long)ft_strlen(base))
		ft_fill_number(str, base, len - 1, nbr / ft_strlen(base));
	str[len - 1] = base[nbr % ft_strlen(base)];
}

char	*ft_ulltoa_base(unsigned long long n, const char *base)
{
	unsigned long long	nbr;
	size_t				nb_len;
	char				*str;

	nbr = n;
	nb_len = ft_ulllen_base(nbr, ft_strlen(base));
	str = ft_calloc(nb_len + 1, sizeof(char));
	if (!str)
		return (NULL);
	ft_fill_number(str, base, nb_len, nbr);
	return (str);
}
