/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opt_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 19:16:17 by kiroussa          #+#    #+#             */
/*   Updated: 2024/05/25 04:48:21 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/opt.h>

t_opt_args	ft_opt_args(int argc, char **argv, int flags,
					const char *optstring)
{
	const bool	posix = flags & OPT_POSIX;
	const bool	bash_like = flags & OPT_BASH_LIKE;

	return ((t_opt_args){argc, argv, posix, bash_like, optstring, NULL});
}
