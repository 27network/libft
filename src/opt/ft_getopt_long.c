/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getopt_long.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 14:01:53 by kiroussa          #+#    #+#             */
/*   Updated: 2024/03/23 14:09:33 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define FT_OPT_INTERNAL
#include <ft/opt.h>

int	ft_getopt(
	t_opt_args *args,
	const char *options
) {
	return (ft_getopt_internal(
			args,
			options,
			NULL,
			NULL
		));
}

int	ft_getopt_long(
	t_opt_args *args,
	const char *options,
	const struct option *long_options,
	int *opt_index
) {
	return (ft_getopt_internal(
			args,
			options,
			long_options,
			opt_index
		));
}

/**
 * @brief Like getopt_long, but '-' as well as '--' can indicate a long option.
 *
 * If an option that starts with '-' (not '--') doesn't match a long option,
 * but does match a short option, it is parsed as a short option instead.
 */
int	ft_getopt_long_only(
	t_opt_args *args,
	const char *options,
	const struct option *long_options,
	int *opt_index
) {
	return (ft_getopt_long_internal(
			args,
			options,
			long_options,
			opt_index
		));
}
