/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 22:00:53 by kiroussa          #+#    #+#             */
/*   Updated: 2024/05/17 04:06:31 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include <stdint.h>

typedef enum e_str_parseerr
{
	PARSE_SUCCESS = 0,
	PARSE_EMPTY = 1,
	PARSE_NOT_NUMBER = 2,
	PARSE_TOO_BIG = 3,
	PARSE_TOO_SMALL = 4,
	PARSE_NOT_VALID = 5,
	PARSE_NOT_VALID_BASE = 6,
}	t_str_parseerr;

int					ft_atoi(const char *str);
int					ft_atoi_base(const char *str, const char *base);
t_str_parseerr		ft_strtoi(const char *str, int *result);
t_str_parseerr		ft_strtoi_base(const char *str, const char *base,
						int *result);

unsigned int		ft_atoui(const char *str);
// t_parseerr		ft_strtoui(const char *str, unsigned int *result);

double				ft_atof(const char *str);
// t_parseerr		ft_strtof(const char *str, float *result);

long long			ft_atoll(const char *str);
t_str_parseerr		ft_strtoll(const char *str, long long *result);

unsigned long long	ft_atoull(const char *str);
// t_parseerr		ft_strtoull(const char *str, unsigned long long *result);

char				*ft_itoa(int i);
char				*ft_itoa_base(int i, const char *base);

char				*ft_lltoa(long long i);
char				*ft_lltoa_base(long long i, const char *base);

char				*ft_ulltoa(unsigned long long i);
char				*ft_ulltoa_base(unsigned long long i, const char *base);

#endif
