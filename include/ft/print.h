/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xtrm <oss@xtrm.me>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 18:49:57 by xtrm              #+#    #+#             */
/*   Updated: 2023/11/17 03:17:50 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_H
# define PRINT_H

# include <stdarg.h>

/* Standard printing */

void			ft_putchar(char c);
void			ft_putchar_fd(int fd, char c);

void			ft_putstr(const char *s);
void			ft_putstr_fd(int fd, const char *s);

void			ft_putendl(const char *s);
void			ft_putendl_fd(int fd, const char *s);

void			ft_putnbr(long long n);
void			ft_putnbr_fd(int fd, long long n);

/* printf and friends */

int				ft_printf(const char *format, ...);
int				ft_dprintf(int fd, const char *format, ...);
int				ft_vprintf(const char *format, va_list args);
int				ft_vdprintf(int fd, const char *format, va_list args);
int				ft_asprintf(char **str_ptr, const char *format, ...);
int				ft_vasprintf(char **str_ptr, const char *format, va_list args);

char			*ft_format(const char *format, ...);
char			*ft_vformat(const char *format, va_list args);

#endif
