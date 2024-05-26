/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opt_get.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 23:33:18 by kiroussa          #+#    #+#             */
/*   Updated: 2024/05/25 04:59:11 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define __FT_OPT_INTERNAL__
#include <ft/opt.h>

int	ft_opt_get(t_opt_globals *globals, t_opt_args *args)
{
	if (!args->posix)
		return (ft_opt_get_long(globals, args, NULL, NULL));
	return (ft_opt_get_posix(globals, args));
}
