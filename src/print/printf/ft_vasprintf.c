/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vasprintf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 14:26:12 by kiroussa          #+#    #+#             */
/*   Updated: 2024/03/22 18:45:11 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define FT_INTERNAL_ACCESS
#include <ft/internal/printf.h>

static int	pf_handle_spec(
		char **str_ptr,
		t_fmt_spec *spec,
		va_list args,
		int length
) {
	char		*final_fmt;
	int			len;

	if (!spec)
		return (0);
	spec->_current_length = length;
	final_fmt = pf_format_spec(spec, args, &len);
	pf_free_spec(spec);
	pf_append(str_ptr, length, final_fmt, len);
	free(final_fmt);
	return (len);
}

static int	pf_copyback(
		char **str_ptr,
		const char *fmt,
		int copy_length,
		int dest_len
) {
	char	*tmp;
	int		length;

	tmp = ft_substr(fmt, 0, copy_length);
	if (!tmp)
		return (0);
	pf_append(str_ptr, dest_len, tmp, ft_strlen(tmp));
	length = ft_strlen(tmp);
	free(tmp);
	return (length);
}

static t_str	*pf_handle_format(
		const char *fmt,
		int *i,
		int *last_i,
		va_list args
) {
	t_str		*str;
	t_fmt_spec	*spec;

	str = pf_str_create(NULL, 0);
	if (!str)
		return (NULL);
	if (*last_i != -1)
		str->length += pf_copyback(
				&str->inner, fmt + *last_i, *i - *last_i, str->length);
	if (*last_i != -1)
		*last_i = -1;
	spec = pf_new_spec(&fmt[*i] + 1, i, args);
	str->length += pf_handle_spec(&str->inner, spec, args, str->length);
	return (str);
}

int	ft_vasprintf(char **str_ptr, const char *fmt, va_list args)
{
	t_str	str;
	int		i;
	int		last_i;

	if (!fmt)
		return (-1);
	pf_str_init(&str, NULL, 0);
	i = 0;
	last_i = -1;
	while (fmt[i])
	{
		if (fmt[i] == *PF_FORMAT_SYMBOL)
			pf_str_append(&str, pf_handle_format(fmt, &i, &last_i, args));
		else
		{
			if (last_i == -1)
				last_i = i;
			i++;
		}
	}
	*str_ptr = str.inner;
	if (last_i != -1)
		str.length += pf_copyback(
				str_ptr, fmt + last_i, i - last_i, str.length);
	return (str.length);
}
