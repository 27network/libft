/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 14:25:49 by kiroussa          #+#    #+#             */
/*   Updated: 2024/03/22 18:47:26 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# undef PRINTF_H
# ifndef __FT_INTERNAL_PRINTF_H__
#  define __FT_INTERNAL_PRINTF_H__

#  ifndef FT_INTERNAL_ACCESS
#   error "This file should not be included directly, \
	please include <ft/print.h> instead."
#  else
#   undef FT_INTERNAL_ACCESS
#  endif

#  include <ft/mem.h>
#  include <ft/print.h>
#  include <ft/string/parse.h>
#  include <ft/string.h>

#  include <stdarg.h>
#  include <unistd.h>

#  ifndef PF_FORMAT_SYMBOL
#   define PF_FORMAT_SYMBOL "%" 
#  endif // PF_FORMAT_SYMBOL

#  ifndef PF_FLAGS
#   define PF_FLAGS "-0 #+"
#  endif // PF_FLAGS

#  ifndef PF_SPECIFIERS
#   define PF_SPECIFIERS "cfspdiuxX%nm"
#  endif // PF_SPECIFIERS

#  define PF_LEFT_JUSTIFY	1  // (1 << 0)
#  define PF_ZERO_PAD		2  // (1 << 1)
#  define PF_SPACE			4  // (1 << 2)
#  define PF_HASH			8  // (1 << 3)
#  define PF_PLUS			16 // (1 << 4)

typedef struct s_fmt_spec
{
	uint8_t	flags;
	int		width;
	int		precision;

	char	*length;
	char	specifier;

	char	*raw;
	int		_current_length;
}	t_fmt_spec;

/* Parsing & formatting */

t_fmt_spec	*pf_new_spec(const char *fmt, int *i, va_list args);
t_fmt_spec	*pf_parse_spec(const char *format, va_list args);
char		*pf_format_spec(t_fmt_spec *spec, va_list args, int *len);
void		pf_free_spec(t_fmt_spec *spec);

/* Formatters */

typedef char	*(*t_type_formatter)(t_fmt_spec *spec, va_list args);

char		*pf_format_char(t_fmt_spec *spec, va_list args);
char		*pf_format_float(t_fmt_spec *spec, va_list args);
char		*pf_format_hex(t_fmt_spec *spec, va_list args);
char		*pf_format_int(t_fmt_spec *spec, va_list args);
char		*pf_format_percent(t_fmt_spec *spec, va_list args);
char		*pf_format_pointer(t_fmt_spec *spec, va_list args);
char		*pf_format_string(t_fmt_spec *spec, va_list args);
char		*pf_format_uint(t_fmt_spec *spec, va_list args);

char		*pf_format_lenptr(t_fmt_spec *spec, va_list args);
char		*pf_format_strerror(t_fmt_spec *spec, va_list args);

/* Flag mutators */

char		*pf_hash_mutator_prefix(t_fmt_spec *spec, char *str);

char		*pf_leftjustify_mutator(t_fmt_spec *spec, char *str);

char		*pf_padding_mutator(t_fmt_spec *spec, char *str);

char		*pf_precision_mutator_str(t_fmt_spec *spec, char *str);
char		*pf_precision_mutator_int(t_fmt_spec *spec, char *str);

/* String */

typedef struct s_str
{
	char	*inner;
	size_t	length;
}	t_str;

void		pf_str_init(t_str *self, char *str, size_t length);
t_str		*pf_str_create(char *str, size_t length);
t_str		*pf_str_append(t_str *self, t_str *other);

/* Utils */

/**
 * @brief	Prepends a sign to a string based on the format flags.
 *
 * @param	spec	The format specifier.
 * @param	str		The string to prepend the sign to.
 * @param	neg		Whether the number is negative.
 *
 * @return	The string with the sign prepended.
 *
 * @note	The string `str` must be freed by the caller.
 */
char		*pf_prepend_sign(t_fmt_spec *spec, char *str, int neg);
char		*pf_strnjoin(char *s1, size_t n1, char *s2, size_t n2);
void		pf_append(char **dest, int dest_len, char *src, int src_len);

# endif // __FT_INTERNAL_PRINTF_H__
#endif // PRINTF_H
