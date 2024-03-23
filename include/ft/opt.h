/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 16:13:22 by kiroussa          #+#    #+#             */
/*   Updated: 2024/03/23 14:14:24 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPT_H
# define OPT_H
# undef OPT_H
# ifndef __FT_OPT_H__
#  define __FT_OPT_H__

/**
 * @brief An enumeration of argument types
 */
enum e_arg_type
{
	no_argument = 0,
	required_argument = 1,
	optional_argument = 2
};

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
 * @param argc The number of arguments.
 * @param argv The arguments (cannot be NULL).
 *
 * @return (t_opt_args) The structure holding our program's arguments
 */
t_opt_args		ft_opt_args(int argc, char *const *argv);
__attribute__((nonnull(2)));

/**
 * @brief A structure holding our program's global variables, obtainable via
 *		`ft_opt_globals()`
 */
typedef struct s_opt_globals
{
	/**
	 * @brief For communication from 'getopt' to the caller. 
	 *
	 * When 'getopt' finds an option that takes an argument, the argument value
	 * is returned here. Also, when 'ordering' is RETURN_IN_ORDER, each
	 * non-option ARGV-element is returned here.
	 */
	char	*optarg;
	/**
	 * @brief Index in ARGV of the next element to be scanned.
	 * This is used for communication to and from the caller
	 * and for communication between successive calls to 'getopt'.
	 *
	 * On entry to 'getopt', zero means this is the first call; initialize.
	 *
	 * When 'getopt' returns -1, this is the index of the first of the
	 * non-option elements that the caller should itself scan.
	 *
	 * Otherwise, 'optind' communicates from one call to the next
	 * how much of ARGV has been scanned so far.
	 */
	int		optind;
	/**
	 * @brief Callers store zero here to inhibit the error message 'getopt'
	 * prints for unrecognized options.
	 */
	int		opterr;
	/**
	 * @brief Set to an option character which was unrecognized.
	 */
	int		optopt;
}	t_opt_globals;

/**
 * @brief Provides a structure holding our program's global variables
 *
 * @return (t_opt_globals *) A pointer to the t_opt_globals struct 
 */
t_opt_globals	*ft_opt_globals(void);

/**
 * @brief The getopt arguments
 */
typedef struct s_opt_params
{
	/**
	 * @brief The program's arguments
	 */
	t_opt_args				args;
	/**
	 * @brief The string of valid options
	 */
	const char				*optstring;
	/**
	 * @brief The long options, see `struct s_option`
	 * @note This can be NULL
	 */
	const struct s_option	*longopts;
	/**
	 * @brief The index of the long option
	 * @note This can be NULL
	 */
	int						*longind;
}	t_opt_params;

t_opt_params	ft_opt_params(t_opt_args args, const char *optstring,
					const struct s_option *longopts, int *longind);

/**
 * @brief A replica of GNU's getopt function.
 *
 * @param args The program's arguments, see `ft_opt_args()`
 * @param optstring The string of valid options
 *
 * @return (int) The next option character from `optstring`, or -1 when no more
 */
int				ft_getopt(t_opt_args args, const char *optstring);
__attribute__((nonnull(2)));

/**
 * @brief Describe the long-named options requested by the application.
 *
 * The LONG_OPTIONS argument to getopt_long or getopt_long_only is a vector
 * of 'struct option' terminated by an element containing a name which is
 * zero.
 *
 * The field 'has_arg' is:
 * no_argument			(or 0) if the option does not take an argument,
 * required_argument	(or 1) if the option requires an argument,
 * optional_argument 	(or 2) if the option takes an optional argument.
 *
 * If the field 'flag' is not NULL, it points to a variable that is set
 * to the value given in the field 'val' when the option is found, but
 * left unchanged if the option is not found.
 *
 * To have a long-named option do something other than set an 'int' to
 * a compiled-in constant, such as set a value from 'optarg', set the
 * option's 'flag' field to zero and its 'val' field to a nonzero
 * value (the equivalent single-letter option character, if there is
 * one).  For long options that have a zero 'flag' field, 'getopt'
 * returns the contents of the 'val' field.
 */
struct s_option
{
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

#  ifdef FT_OPT_INTERNAL

int				ft_getopt_internal(t_opt_args args, const char *optstring,
					const struct s_option *longopts, int *longind);
int				ft_getopt_long_internal(t_opt_args args, const char *optstring,
					const struct s_option *longopts, int *longind);

#  endif // FT_OPT_INTERNAL

# endif // __FT_OPT_H__
#endif // OPT_H
