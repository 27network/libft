/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opt_get_posix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 20:48:14 by kiroussa          #+#    #+#             */
/*   Updated: 2024/05/25 05:33:22 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/mem.h>
#define __FT_OPT_INTERNAL__
#include <ft/opt.h>
#include <ft/string.h>
#include <ft/wchar.h>
#include <wchar.h>
#include <limits.h>

#define TARGET_ARG	0
#define TARGET_OPT	1

static int	ft_getopt_prelude(
	t_opt_globals *g_opt,
	t_opt_args *args
) {
	if (g_opt->optind >= args->argc || !args->argv[g_opt->optind])
		return (-1);
	if (args->argv[g_opt->optind][0] != '-')
	{
		if (args->optstring[0] == '-')
			g_opt->optarg = args->argv[g_opt->optind++];
		if (args->optstring[0] == '-')
			return (1);
		return (-1);
	}
	if (!args->argv[g_opt->optind][1])
		return (-1);
	if (args->argv[g_opt->optind][1] == '-' && !args->argv[g_opt->optind][2])
	{
		g_opt->optind += 1;
		return (-1);
	}
	if (!g_opt->_optpos)
		g_opt->_optpos += 1;
	return (0);
}

static int	ft_getopt_handle_arguments(
	t_opt_globals *g_opt,
	t_opt_args *args,
	wchar_t *chars,
	int i
) {
	if (args->optstring[i] != ':')
		return (chars[TARGET_OPT]);
	g_opt->optarg = 0;
	if (args->optstring[i + 1] != ':' || g_opt->_optpos)
	{
		g_opt->optarg = args->argv[g_opt->optind++];
		if (g_opt->_optpos)
			g_opt->optarg += g_opt->_optpos;
		g_opt->_optpos = 0;
	}
	if (g_opt->optind > args->argc)
	{
		g_opt->optopt = chars[TARGET_ARG];
		if (args->optstring[0] == ':')
			return (':');
		if (g_opt->opterr)
			ft_opt_msg(args->argv[0], ": option requires an argument: ",
				g_opt->_optchar, g_opt->_optchar_len);
		return ('?');
	}
	return (chars[TARGET_ARG]);
}

static int	ft_getopt_handle_unknown(
	t_opt_globals *g_opt,
	t_opt_args *args,
	wchar_t *chars,
	int i
) {
	if (!(chars[TARGET_ARG] != chars[TARGET_OPT] || chars[TARGET_ARG] == ':'))
		return (ft_getopt_handle_arguments(g_opt, args, chars, i));
	g_opt->optopt = chars[TARGET_ARG];
	if (g_opt->_optchar_len == 1 && g_opt->_optchar[0] == '-'
		&& args->bash_like)
	{
		if (!ft_strcmp(args->argv[g_opt->optind], "--help"))
		{
			g_opt->optind += 1;
			g_opt->_optpos = 0;
			return (HELP_OPT);
		}
	}
	if (args->optstring[0] != ':' && g_opt->opterr)
		ft_opt_msg(args->argv[0], ": unrecognized option: ", g_opt->_optchar,
			g_opt->_optchar_len);
	return ('?');
}

static int	ft_getopt_seek_target_opt(
	wchar_t *chars,
	const char *optstring
) {
	int	i;
	int	l;

	i = 0;
	while (1)
	{
		l = ft_mbtowc(&chars[TARGET_OPT], optstring + i, MB_LEN_MAX);
		if (l > 0)
			i += l;
		else
			i++;
		if (!l || chars[TARGET_ARG] == chars[TARGET_OPT])
			break ;
	}
	return (i);
}

int	ft_opt_get_posix(
	t_opt_globals *g_opt,
	t_opt_args *args
) {
	const int	prelude = ft_getopt_prelude(g_opt, args);
	int			i;
	wchar_t		chars[2];

	if (prelude != 0)
		return (prelude);
	ft_bzero(chars, sizeof(chars));
	g_opt->_optchar_len = ft_mbtowc(&chars[TARGET_ARG],
			args->argv[g_opt->optind] + g_opt->_optpos, MB_LEN_MAX);
	if (g_opt->_optchar_len < 0)
		chars[TARGET_ARG] = 0xfffd;
	if (g_opt->_optchar_len < 0)
		g_opt->_optchar_len = 1;
	g_opt->_optchar = args->argv[g_opt->optind] + g_opt->_optpos;
	g_opt->_optpos += g_opt->_optchar_len;
	if (!args->argv[g_opt->optind][g_opt->_optpos])
	{
		g_opt->optind += 1;
		g_opt->_optpos = 0;
	}
	if (args->optstring[0] == '-' || args->optstring[0] == '+')
		args->optstring++;
	i = ft_getopt_seek_target_opt(chars, args->optstring);
	return (ft_getopt_handle_unknown(g_opt, args, chars, i));
}
