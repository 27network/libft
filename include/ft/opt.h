/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 19:02:35 by kiroussa          #+#    #+#             */
/*   Updated: 2024/05/25 05:01:47 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPT_H
# define OPT_H
# undef OPT_H
# ifndef __FT_OPT_H__
#  define __FT_OPT_H__

#  include <stdbool.h>
#  include <stddef.h>

/* Globals */

typedef struct s_opt_globals
{
	char	*optarg;
	int		optind;
	int		optopt;
	int		opterr;

	int		_optpos;

	char	*_optchar;
	int		_optchar_len;
}	t_opt_globals;

t_opt_globals	ft_opt_globals(void);
void			ft_opt_reset(t_opt_globals *globals);

/* Arguments */

#  define OPT_POSIX 0x1
#  define OPT_BASH_LIKE 0x2

#  define HELP_OPT -99

typedef struct s_opt_option	t_opt_option;

/**
 * @brief Arguments for the getopt functions.
 *
 * @param argc			Number of arguments.
 * @param argv			Arguments as an array of string.
 * @param posix			Whether to use POSIX mode
 *						)this disables the '+' and '-' options).
 * @param bash_like		Whether to use bash-like mode
 *						(this allows --help to be accepted as a special option).
 * @param optstring		Option string for getopt.
 * @param _longopts		Long options for getopt_long, internal storage.
 */
typedef struct s_opt_args
{
	int					argc;
	char				**argv;
	bool				posix;
	bool				bash_like;
	const char			*optstring;
	const t_opt_option	*_longopts;
}	t_opt_args;

t_opt_args		ft_opt_args(int argc, char **argv, int flags,
					const char *optstring);

/* getopt */

int				ft_opt_get(t_opt_globals *g_opt, t_opt_args *args);

/* getopt_long */

enum e_argument_req
{
	no_argument = 0,
	required_argument = 1,
	optional_argument = 2
};

typedef struct s_opt_option
{
	const char	*name;
	int			has_arg;
	int			*flag;
	int			val;
}	t_opt_option;

int				ft_opt_get_long(t_opt_globals *g_opt, t_opt_args *args,
					const t_opt_option *longopts, int *longindex);

#  ifdef __FT_OPT_INTERNAL__

int				ft_opt_get_posix(t_opt_globals *g_opt, t_opt_args *args);
int				ft_opt_get_long_core(t_opt_globals *g_opt, t_opt_args *args,
					const t_opt_option *longopts, int *idx);

void			ft_opt_permute(char **argv, int from, int to);
void			ft_opt_msg(const char *a, const char *b,
					const char *c, size_t size_c);

#  endif // __FT_OPT_INTERNAL__

# endif // __FT_OPT_H__
#endif // OPT_H
