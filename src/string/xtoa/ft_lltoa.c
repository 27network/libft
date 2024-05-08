/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 15:40:19 by kiroussa          #+#    #+#             */
/*   Updated: 2024/05/08 15:23:00 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/string/parse.h>
#include <ft/string.h>
#include <limits.h>

char	*ft_lltoa(long long n)
{
	return (ft_lltoa_base(n, "0123456789"));
}

char	*ft_itoa(int n)
{
	return (ft_lltoa(n));
}
