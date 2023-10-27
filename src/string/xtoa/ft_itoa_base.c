/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 15:03:18 by kiroussa          #+#    #+#             */
/*   Updated: 2023/10/26 15:39:01 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/macros.h>
#include <ft/string.h>
#include <stdlib.h>

PRIVATE void	ft_fill_number(
		char *str, 
		const char *base, 
		size_t len, 
		long long nbr
) {
	if (nbr > 9)
		ft_fill_number(str, base, len - 1, nbr / 10);
	str[len - 1] = base[nbr % ft_strlen(base)];
}

char	*ft_itoa_base(long long n, const char *base)
{
	long long	nbr;
	size_t		nb_len;
	char		*str;

	nbr = n;
	nb_len = ft_nblen(nbr);
	str = malloc((nb_len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[nb_len] = 0;
	if (nbr < 0)
		str[0] = '-';
	if (nbr < 0)
		ft_fill_number(str + 1, base, nb_len - 1, -nbr);
	else
		ft_fill_number(str, base, nb_len, nbr);
	return (str);
}
