/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 16:04:26 by kiroussa          #+#    #+#             */
/*   Updated: 2024/05/19 03:57:58 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

DEFINE_TEST(simple, "Can parse simple numbers", {
	long long		result;
	t_str_parseerr	err;

	err = ft_strtoll("42", &result);
	ASSERT(err == PARSE_SUCCESS);
	ASSERT(result == 42);

	err = ft_strtoll("0", &result);
	ASSERT(err == PARSE_SUCCESS);
	ASSERT(result == 0);

	err = ft_strtoll("-42", &result);
	ASSERT(err == PARSE_SUCCESS);
	ASSERT(result == -42);

	err = ft_strtoll("-0", &result);
	ASSERT(err == PARSE_SUCCESS);
	ASSERT(result == 0);

	err = ft_strtoll("-1", &result);
	ASSERT(err == PARSE_SUCCESS);
	ASSERT(result == -1);
});

DEFINE_TEST(spaces, "Can parse simple numbers with leading spaces", {
	long long		result;
	t_str_parseerr	err;

	err = ft_strtoll("  42", &result);
	ASSERT(err == PARSE_SUCCESS);
	ASSERT(result == 42);

	err = ft_strtoll("  \t\n0", &result);
	ASSERT(err == PARSE_SUCCESS);
	ASSERT(result == 0);

	err = ft_strtoll("  -42", &result);
	ASSERT(err == PARSE_SUCCESS);
	ASSERT(result == -42);

	err = ft_strtoll("  \t\n-0", &result);
	ASSERT(err == PARSE_SUCCESS);
	ASSERT(result == 0);
});

DEFINE_TEST(maxval, "Can parse max value", {
	long long		result;
	t_str_parseerr	err;

	err = ft_strtoll("9223372036854775807", &result);
	ASSERT(err == PARSE_SUCCESS);
	ASSERT(result == 9223372036854775807);
});

DEFINE_TEST(minval, "Can parse min value", {
	long long		result;
	t_str_parseerr	err;

	err = ft_strtoll("-9223372036854775808", &result);
	ASSERT(err == PARSE_SUCCESS);
	ASSERT(result == -9223372036854775807 - 1);
});

DEFINE_TEST(ddoverflow, "Detects overflow", {
	long long		result;
	t_str_parseerr	err;

	err = ft_strtoll("9223372036854775808", &result);
	ASSERT(err == PARSE_TOO_BIG);

	err = ft_strtoll("9223372036854775809", &result);
	ASSERT(err == PARSE_TOO_BIG);

	for (int i = 5810; i < 9999; i++) {
		char buf[100];
		sprintf(buf, "922337203685477%d", i);
		err = ft_strtoll(buf, &result);
		ASSERT(err == PARSE_TOO_BIG);
	}
});

DEFINE_TEST(underflow, "Detects underflow", {
	long long		result;
	t_str_parseerr	err;

	err = ft_strtoll("-9223372036854775809", &result);
	ASSERT(err == PARSE_TOO_SMALL);

	err = ft_strtoll("-9223372036854775810", &result);
	ASSERT(err == PARSE_TOO_SMALL);

	for (int i = 5811; i < 9999; i++) {
		char buf[100];
		sprintf(buf, "-922337203685477%d", i);
		err = ft_strtoll(buf, &result);
		ASSERT(err == PARSE_TOO_SMALL);
	}
});
