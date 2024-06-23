/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 20:36:30 by kiroussa          #+#    #+#             */
/*   Updated: 2024/06/23 06:35:18 by kiroussa         ###   ########.fr       */
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
void			*ft_realloc(void *ptr, size_t old_size, size_t new_size);

#  ifndef __FT_MEM_NO_EXTERNS__

extern void		free(void *ptr);

#  endif // __FT_MEM_NO_EXTERNS__

# endif // __FT_MEM_H__
#endif // MEM_H
