/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 20:36:30 by kiroussa          #+#    #+#             */
/*   Updated: 2024/03/22 18:38:27 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEM_H
# define MEM_H
# undef MEM_H
# ifndef __FT_MEM_H__
#  define __FT_MEM_H__

#  include <stddef.h>

void			*ft_memset(void *s, int c, size_t n);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *s1, const void *s2, size_t n);
void			*ft_memccpy(void *s1, const void *s2, int c, size_t n);
void			*ft_memmove(void *s1, const void *s2, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);

void			*ft_calloc(size_t nelem, size_t elsize);

#  ifndef FT_MEM_NO_EXTERNS

extern void		free(void *ptr);

#  endif // FT_MEM_NO_EXTERNS

# endif // __FT_MEM_H__
#endif // MEM_H
