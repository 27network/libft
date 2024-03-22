/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 22:18:11 by kiroussa          #+#    #+#             */
/*   Updated: 2024/03/22 18:33:36 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATH_H
# define MATH_H
# undef MATH_H
# ifndef __FT_MATH_H__
#  define __FT_MATH_H__

#  include <stdint.h>

int64_t		ft_abs(int64_t n);
int64_t		ft_pow(int64_t n, uint64_t pow);
uint64_t	ft_sqrt(uint64_t n);

int64_t		ft_min(int64_t a, int64_t b);
int64_t		ft_max(int64_t a, int64_t b);

double		ft_fabs(double n);
double		ft_fpow(double n, uint64_t pow);
// double	ft_fsqrt(double n);

double		ft_fmin(double a, double b);
double		ft_fmax(double a, double b);

# endif // __FT_MATH_H__
#endif // MATH_H
