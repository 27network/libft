/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 01:58:47 by kiroussa          #+#    #+#             */
/*   Updated: 2023/10/27 02:07:30 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

#define BASE_10 "0123456789"
#define BASE_2 "01"
#define BASE_16 "0123456789abcdef"

TEST_ENTRY("ft_itoa_base",
	TEST("test base 10", 
		ASSERT(!strcmp(ft_itoa_base(10, BASE_10), "10"));
		ASSERT(!strcmp(ft_itoa_base(0, BASE_10), "0"));
		ASSERT(!strcmp(ft_itoa_base(-10, BASE_10), "-10"));
		ASSERT(!strcmp(ft_itoa_base(2147483647, BASE_10), "2147483647"));
		ASSERT(!strcmp(ft_itoa_base(-2147483648, BASE_10), "-2147483648"));
	)
	TEST("test base 2",
		ASSERT(!strcmp(ft_itoa_base(10, BASE_2), "1010"));
		ASSERT(!strcmp(ft_itoa_base(0, BASE_2), "0"));
		ASSERT(!strcmp(ft_itoa_base(-10, BASE_2), "-1010"));
		ASSERT(!strcmp(ft_itoa_base(42, BASE_2), "101010"));
	)
	TEST("test base 16",
		ASSERT(!strcmp(ft_itoa_base(10, BASE_16), "a"));
		ASSERT(!strcmp(ft_itoa_base(0, BASE_16), "0"));
		ASSERT(!strcmp(ft_itoa_base(-10, BASE_16), "-a"));
		ASSERT(!strcmp(ft_itoa_base(42, BASE_16), "2a"));
		ASSERT(!strcmp(ft_itoa_base(48879, BASE_16), "beef"));
	)
)

