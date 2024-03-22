/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 03:36:07 by kiroussa          #+#    #+#             */
/*   Updated: 2024/03/22 18:41:47 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_H
# define GNL_H
# undef GNL_H
# ifndef __FT_INTERNAL_GNL_H__
#  define __FT_INTERNAL_GNL_H__

#  ifndef FT_INTERNAL_ACCESS
#   error "This file should not be included directly, \
	please include <ft/io.h> instead."
#  else
#   undef FT_INTERNAL_ACCESS
#  endif

#  include <ft/io.h>
#  include <ft/mem.h>
#  include <ft/string.h>

#  include <stdlib.h>
#  include <unistd.h>

typedef struct s_gnl
{
	char	*inner;
	size_t	size;
}	t_gnl;

# endif // __FT_INTERNAL_GNL_H__
#endif // GNL_H
