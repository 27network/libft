/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opt_get_long.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 13:01:15 by kiroussa          #+#    #+#             */
/*   Updated: 2024/05/24 15:39:35 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define __FT_OPT_INTERNAL__ 
#include <ft/opt.h>

static void	ft_permute_args(t_opt_globals *g_opt, t_opt_args *args,
				int skipped, int resumed)
{
	const int	cnt = g_opt->optind - resumed;
	int			i;

	if (resumed > skipped)
	{
		i = 0;
		while (i < cnt)
		{
			ft_opt_permute(args->argv, skipped, g_opt->optind - 1);
			i++;
		}
		g_opt->optind = skipped + cnt;
	}
}

int	ft_opt_get_long(t_opt_globals *g_opt, t_opt_args *args,
		const t_opt_option *longopts, int *idx)
{
	int	ret;
	int	i;
	int	skipped;
	int	resumed;

	if (g_opt->optind >= args->argc || !args->argv[g_opt->optind])
		return (-1);
	skipped = g_opt->optind;
	if (args->optstring[0] != '+' && args->optstring[0] != '-')
	{
		i = g_opt->optind;
		while (1)
		{
			if (i >= args->argc || !args->argv[i])
				return (-1);
			if (args->argv[i][0] == '-' && args->argv[i][1])
				break ;
			i++;
		}
		g_opt->optind = i;
	}
	resumed = g_opt->optind;
	ret = ft_opt_get_long_core(g_opt, args, longopts, idx);
	ft_permute_args(g_opt, args, skipped, resumed);
	return (ret);
}
