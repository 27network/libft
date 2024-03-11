/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opt_globals.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 16:30:45 by kiroussa          #+#    #+#             */
/*   Updated: 2024/03/11 06:48:30 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/opt.h>
#include <stddef.h>

t_opt_globals	*ft_opt_globals(void)
{
	static t_opt_globals	globals;
	static int				init = 0;

	if (!init)
	{
		globals.optind = 1;
		globals.opterr = 1;
		globals.optopt = 0;
		globals.optpos = 0;
		globals.__optreset = 0;
		globals.optarg = NULL;
		init = 1;
	}
	return (&globals);
}
