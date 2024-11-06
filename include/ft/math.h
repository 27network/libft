/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 22:18:11 by kiroussa          #+#    #+#             */
/*   Updated: 2024/11/07 00:02:54 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATH_H
# define MATH_H
# undef MATH_H
# ifndef __FT_MATH_H__
#  define __FT_MATH_H__

#  include <stdint.h>

#  ifndef FLOATING_SIZE
#   define FLOATING_SIZE 8
#  endif // FLOATING_SIZE

#  if FLOATING_SIZE == 4

typedef float	t_floating;

#  elif FLOATING_SIZE == 8

typedef double	t_floating;

#  else
#   error "FLOATING_SIZE must be either 4 or 8"
#  endif // FLOATING_SIZE

#  ifdef __FT_FAST_MATH_STRUCTS

typedef union u_int_store
{
	int			i;
	float		f;
}	t_int_store;

#  endif // __FT_FAST_MATH_STRUCTS

int64_t		ft_abs(int64_t n);
double		ft_pow(double n, uint64_t pow);
double		ft_sqrt(double n);

int64_t		ft_min(int64_t a, int64_t b);
int64_t		ft_max(int64_t a, int64_t b);

int			ft_sign(int64_t n);

double		ft_fabs(double n);
float		ft_fpow(float n, float y);
// double	ft_fsqrt(double n);

double		ft_fmin(double a, double b);
double		ft_fmax(double a, double b);

int			ft_fsign(double n);

float		ft_sin(float n);
float		ft_cos(float n);

# endif // __FT_MATH_H__
#endif // MATH_H
