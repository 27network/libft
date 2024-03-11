/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 16:13:22 by kiroussa          #+#    #+#             */
/*   Updated: 2024/03/11 06:38:56 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPT_H
# define OPT_H

# define NO_ARGUMENT        0
# define REQUIRED_ARGUMENT  1
# define OPTIONAL_ARGUMENT  2

/**
 * @brief A structure holding our program's arguments
 */
typedef struct s_opt_args
{
	int			argc;
	char *const	*argv;
}	t_opt_args;

/**
 * @brief Provides a structure holding our program's arguments
 *
 * @param argc The number of arguments
 * @param argv The arguments
 *
 * @return (t_opt_args) The structure holding our program's arguments
 */
t_opt_args		ft_opt_args(int argc, char *const *argv);

/**
 * @brief A structure holding our program's global variables, obtainable via
 *		`ft_opt_globals()`
 */
typedef struct s_opt_globals
{
	int			optind;
	int			opterr;
	int			optopt;
	int			optpos;
	int			__optreset;
	char		*optarg;
	char		*optchar;
	int			__k;
}	t_opt_globals;

/**
 * @brief Provides a structure holding our program's global variables
 *
 * @return (t_opt_globals *) A pointer to the t_opt_globals struct 
 */
t_opt_globals	*ft_opt_globals(void);

/**
 * @brief A replica of GNU's getopt function.
 *
 * @param args The program's arguments, see `ft_opt_args()`
 * @param optstring The string of valid options
 *
 * @return (int) The next option character from `optstring`, or -1 when no more
 */
int				ft_getopt(t_opt_args args, const char *optstring);

/**
 * @brief A representation of a long option
 */
struct s_option {
	const char	*name;
	int			has_arg;
	int			*flag;
	int			val;
};

/**
 * @brief A replica of GNU's getopt_long function.
 *
 * @param args The program's arguments, see `ft_opt_args()`
 * @param optstring The string of valid options
 * @param longopts The long options, see `struct s_option`
 * @param idx The index of the long option
 *
 * @return (int) The next option character from `optstring`, or -1 when no more
 */
int				ft_getopt_long(t_opt_args args, const char *optstring,
					const struct s_option *longopts, int *idx);

/**
 * @brief A replica of GNU's getopt_long_only function.
 * 
 * @param args The program's arguments, see `ft_opt_args()`
 * @param optstring The string of valid options
 * @param longopts The long options, see `struct s_option`
 * @param idx The index of the long option
 *
 * @return (int) The next option character from `optstring`, or -1 when no more
 */
int				ft_getopt_long_only(t_opt_args args, const char *optstring,
					const struct s_option *longopts, int *idx);

#endif // OPT_H
