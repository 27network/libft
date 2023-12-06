/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 22:00:53 by kiroussa          #+#    #+#             */
/*   Updated: 2023/12/06 23:04:03 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include <stdint.h>

typedef enum e_parseerr
{
	PARSE_SUCCESS = 0,
	PARSE_EMPTY = 1,
	PARSE_NOT_NUMBER = 2,
	PARSE_TOO_BIG = 3,
	PARSE_TOO_SMALL = 4,
	PARSE_NOT_VALID = 5
}	t_parseerr;

int					ft_atoi(const char *str);
int					ft_atoi_base(const char *str, const char *base);
t_parseerr			ft_strtoi(const char *str, int *result);

unsigned int		ft_atoui(const char *str);
// t_parseerr		ft_strtoui(const char *str, unsigned int *result);

float				ft_atof(const char *str);
// t_parseerr		ft_strtof(const char *str, float *result);

double				ft_atod(const char *str);
// t_parseerr		ft_strtod(const char *str, double *result);

long double			ft_atold(const char *str);
// t_parseerr		ft_strtold(const char *str, long double *result);

long long			ft_atoll(const char *str);
// t_parseerr		ft_strtoll(const char *str, long long *result);

unsigned long long	ft_atoull(const char *str);
// t_parseerr		ft_strtoull(const char *str, unsigned long long *result);

char				*ft_lltoa(long long i);
char				*ft_lltoa_base(long long i, const char *base);

char				*ft_ulltoa(unsigned long long i);
char				*ft_ulltoa_base(unsigned long long i, const char *base);

#endif
