/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opt_get_long_core.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 23:20:28 by kiroussa          #+#    #+#             */
/*   Updated: 2024/05/25 05:05:20 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define __FT_OPT_INTERNAL__
#include <ft/opt.h>
#include <ft/string.h>
#include <ft/wchar.h>
#include <limits.h>

#include <stdio.h>
#include <stdlib.h>

#define UNRECOGNIZED_OPTION ": unrecognized option: "
#define AMBIGUOUS_OPTION ": option is ambiguous: "
#define REQUIRED_ARG ": option requires an argument: "

/*
static int	ft_opt_long_part_last(
	t_opt_globals *g_opt,
	t_opt_args *args,
	int colon,
	int cnt
) {
	const char	*msg;
	char		*opt;

	if (args->argv[g_opt->optind][1] == '-')
	{
		msg = UNRECOGNIZED_OPTION;
		if (cnt)
			msg = AMBIGUOUS_OPTION;
		g_opt->optopt = 0;
		opt = args->argv[g_opt->optind] + 2;
		if (!colon && g_opt->opterr)
			ft_opt_msg(args->argv[0], msg, opt, ft_strlen(opt));
		g_opt->optind++;
		return ('?');
	}
	return (ft_opt_get(g_opt, args));
}

static int	ft_opt_long_part_one(
	const t_opt_option *longopts,
	char ***args,
	char **s,
	int *match
) {
	const char	*n;
	int			i;
	int			cnt;
	char		**arg;
	char		**o;

	i = 0;
	cnt = 0;
	arg = args[0];
	o = args[1];
	while (longopts[i].name && ((i > 0 && !*longopts[i].name || i == 0)))
	{
		n = longopts[i++].name;
		*o = *s;
		*o += **o == '-';
		while (**o && **o != '=' && **o == *n && n++ && (*o)++)
			;
		if (**o && **o != '=')
			continue ;
		*arg = *o;
		*match = i;
		cnt = 1 * !*n + (cnt + 1) * !!*n;
	}
	return (cnt);
}

static int	ft_opt_long_part_two(
	t_opt_globals *g_opt,
	t_opt_args *args,
	char **arg_data,
	int cnt
) {
	int		l;
	int		j;
	int		i;
	char	*arg;
	char	*s;

	arg = arg_data[0];
	s = arg_data[1];
	if (cnt == 1 && args->longonly && arg - s == ft_mblen(s, MB_LEN_MAX))
	{
		l = arg - s;
		i = 0;
		while (args->optstring[i])
		{
			j = 0;
			while (j < l && s[j] == args->optstring[i + j])
				j++;
			if (j == l)
				cnt++;
			i++;
			if (j == l)
				break ;
		}
	}
	return (cnt);
}

static int	ft_opt_long_part_big(
	t_opt_globals *g_opt,
	t_opt_args *args,
	const t_opt_option *longopts,
	int cnt
) {
	const int	colon = args->optstring[args->optstring[0] == '+'
		|| args->optstring[0] == '-'] == ':';
	int			match;
	char		*arg;
	int			*idx;
	int			ret;

	if (cnt == 1)
	{
		g_opt->optind++;
		if (*arg == '=')
		{
			if (!longopts[match].has_arg)
			{
				g_opt->optopt = longopts[match].val;
				if (colon || !g_opt->opterr)
					return ('?');
				ft_opt_msg(args->argv[0],
					": option does not take an argument: ",
					longopts[match].name,
					ft_strlen(longopts[match].name));
				return ('?');
			}
			g_opt->optarg = arg + 1;
		}
		else if (longopts[match].has_arg == required_argument)
		{
			g_opt->optarg = args->argv[g_opt->optind];
			if (!g_opt->optarg)
			{
				g_opt->optopt = longopts[match].val;
				if (colon)
					return (':');
				if (!g_opt->opterr)
					return ('?');
				ft_opt_msg(args->argv[0], REQUIRED_ARG, longopts[match].name,
					ft_strlen(longopts[match].name));
				return ('?');
			}
			g_opt->optind++;
		}
		if (idx)
			*idx = match;
		if (longopts[match].flag)
			*longopts[match].flag = longopts[match].val;
		if (longopts[match].flag)
			return (0);
		return (longopts[match].val);
	}
	return (ft_opt_long_last(g_opt, args, colon, cnt));
}

int	ft_opt_get_long_core(t_opt_globals *g_opt, t_opt_args *args,
		const t_opt_option *longopts, int *idx)
{
	int		cnt;
	int		match;
	char	*arg;
	char	*opt;
	char	*start;

	g_opt->optarg = 0;
	if (longopts && args->argv[g_opt->optind][0] == '-'
		&& ((args->longonly && args->argv[g_opt->optind][1]
		&& args->argv[g_opt->optind][1] != '-')
		|| (args->argv[g_opt->optind][1] == '-'
		&& args->argv[g_opt->optind][2])))
	{
		arg = args->argv[g_opt->optind] + 1;
		opt = arg;
		start = arg;
		cnt = ft_opt_long_part_one(longopts, (char **[]){&arg, &opt},
				&start, &match);
		cnt = ft_opt_long_part_two(g_opt, args, (char *[]){arg, start}, cnt);
		return (ft_opt_long_part_big(g_opt, args, longopts, cnt));
	}
	return (ft_opt_get(g_opt, args));
}
*/

int	ft_opt_get_long_core(t_opt_globals *g_opt, t_opt_args *args,
		const t_opt_option *longopts, int *idx)
{
	(void)longopts;
	(void)idx;
	return (ft_opt_get_posix(g_opt, args));
}
