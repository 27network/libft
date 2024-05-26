/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opt_permute.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 13:02:24 by kiroussa          #+#    #+#             */
/*   Updated: 2024/05/23 13:03:18 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/opt.h>

void	ft_opt_permute(char **av, int dest, int src)
{
	char	*tmp;
	int		i;

	tmp = av[src];
	i = src;
	while (i > dest)
	{
		av[i] = av[i - 1];
		i--;
	}
	av[dest] = tmp;
}
