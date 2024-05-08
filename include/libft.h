/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 14:28:44 by kiroussa          #+#    #+#             */
/*   Updated: 2024/05/08 15:19:33 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# undef LIBFT_H
# ifndef __LIBFT_H__
#  define __LIBFT_H__

#  define __FT_LIBFT_COMPAT__
#  include <ft/data/list.h>
#  include <ft/math/matrix.h>
#  include <ft/math/vector.h>
#  include <ft/mem/arena.h>
#  include <ft/string/parse.h>
#  include <ft/io.h>
#  include <ft/math.h>
#  define __FT_MEM_NO_EXTERNS__
#  include <ft/mem.h>
#  undef __FT_MEM_NO_EXTERNS__
#  include <ft/print.h>
#  include <ft/string.h>
#  undef __FT_LIBFT_COMPAT__

# endif // __LIBFT_H__
#endif // LIBFT_H
