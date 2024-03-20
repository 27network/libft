/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getopt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 16:32:29 by kiroussa          #+#    #+#             */
/*   Updated: 2024/03/12 01:36:53 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/opt.h>
#include <ft/string.h>
#include <ft/wchar.h>
#include <limits.h>
#include <unistd.h>

static void	__getopt_msg(
	const char *a,
	const char *b,
	const char *c,
	size_t length
) {
	size_t	a_len;

	a_len = ft_strlen(a);
	if (a_len < 0)
		return ;
	(void) write(2, a, a_len);
	(void) write(2, b, ft_strlen(b));
	if (write(2, c, length) == (int) length)
		(void) write(2, "\n", 1);
}

static int	ft_opt_final(
	t_opt_args args,
	const char *optstring,
	int64_t flags,
	t_opt_globals *g_opt
) {
	int	i;

	i = flags & 0xFFFFFFFF;
	if (optstring[i] == ':')
	{
		g_opt->optarg = 0;
		if (optstring[i + 1] != ':' || g_opt->__optpos)
		{
			g_opt->optarg = args.argv[g_opt->optind++];
			if (g_opt->__optpos)
				g_opt->optarg += g_opt->__optpos;
			g_opt->__optpos = 0;
		}
		if (g_opt->optind > args.argc)
		{
			g_opt->optopt = (int)(flags >> 32);
			if (optstring[0] == ':')
				return (':');
			if (g_opt->opterr)
				__getopt_msg(args.argv[0], ": option requires an argument: ",
					g_opt->optchar, g_opt->__k);
			return ('?');
		}
	}
	return ((int)(flags >> 32));
}

static int	ft_opt_loop(
	t_opt_args args,
	const char *optstring,
	wchar_t c,
	t_opt_globals *g_opt
) {
	int64_t	i;
	wchar_t	d;
	int		l;

	i = 0;
	d = 0;
	while (1)
	{
		l = ft_mbtowc(&d, optstring + i, MB_LEN_MAX);
		if (d == c)
			break ;
		if (l > 0)
			i += l;
		else
			i++;
	}
	if (d != c || c == ':')
	{
		g_opt->optopt = c;
		if (optstring[0] != ':' && g_opt->opterr)
			__getopt_msg(args.argv[0], ": unrecognized option: ",
				g_opt->optchar, g_opt->__k);
		return ('?');
	}
	return (ft_opt_final(args, optstring, ((int64_t)c) << 32 | i, g_opt));
}

static int	ft_opt_parse(
	t_opt_args args,
	const char *optstring,
	t_opt_globals *g_opt
) {
	wchar_t	c;

	if (!g_opt->__optpos)
		g_opt->__optpos++;
	g_opt->__k = ft_mbtowc(&c, args.argv[g_opt->optind] + g_opt->__optpos,
			MB_LEN_MAX);
	if (g_opt->__k < 0)
		c = 0xfffd;
	if (g_opt->__k < 0)
		g_opt->__k = 1;
	g_opt->optchar = args.argv[g_opt->optind] + g_opt->__optpos;
	g_opt->__optpos += g_opt->__k;
	if (!args.argv[g_opt->optind][g_opt->__optpos])
	{
		g_opt->optind++;
		g_opt->__optpos = 0;
	}
	if (optstring[0] == '-' || optstring[0] == '+')
		optstring++;
	return (ft_opt_loop(args, optstring, c, g_opt));
}

int	ft_getopt(t_opt_args args, const char *optstring)
{
	t_opt_globals	*g_opt;

	g_opt = ft_opt_globals();
	if (!g_opt->optind || g_opt->__optreset)
	{
		g_opt->__optreset = 0;
		g_opt->__optpos = 0;
		g_opt->optind = 1;
	}
	if (g_opt->optind >= args.argc || !args.argv[g_opt->optind])
		return (-1);
	if (args.argv[g_opt->optind][0] != '-')
	{
		if (optstring[0] == '-')
			optarg = args.argv[g_opt->optind++];
		if (optstring[0] == '-')
			return (1);
		return (-1);
	}
	if (!args.argv[g_opt->optind][1])
		return (-1);
	if (args.argv[g_opt->optind][1] == '-' && !args.argv[g_opt->optind][2])
		return (g_opt->optind++, -1);
	return (ft_opt_parse(args, optstring, g_opt));
}
