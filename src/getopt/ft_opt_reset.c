/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opt_reset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 19:08:41 by kiroussa          #+#    #+#             */
/*   Updated: 2024/05/22 20:57:42 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/opt.h>
#include <stddef.h>

void	ft_opt_reset(t_opt_globals *opt)
{
	opt->optarg = NULL;
	opt->optind = 1;
	opt->optopt = 0;
	opt->opterr = 1;
	opt->_optpos = 0;
}
