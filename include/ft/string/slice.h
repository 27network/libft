/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slice.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 15:43:07 by kiroussa          #+#    #+#             */
/*   Updated: 2024/04/10 17:14:01 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SLICE_H
# define SLICE_H
# undef SLICE_H
# ifndef __FT_STRING_SLICE_H__
#  define __FT_STRING_SLICE_H__

#  include <ft/mem/arena.h>
#  include <stddef.h>

typedef struct s_string
{
	char	*base;
	size_t	length;
}	t_string;

t_string	ft_str(const char *str);
t_string	ft_str_new(const char *str, size_t len);
t_string	*ft_str_alloc(t_arena *arena, const char *base, size_t len);

# endif // __FT_STRING_SLICE_H__
#endif // SLICE_H
